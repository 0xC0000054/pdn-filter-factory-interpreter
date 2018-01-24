/*
*  This file is part of pdn-filter-factory-interpreter,
*  the Filter Factory language interpreter for pdn-filter-factory.
*
*  Copyright (C) 2010, 2011, 2018 Nicholas Hayes
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include <windows.h>
#include <math.h>
#include <new>
#include "ffeval.h"

struct ColorBgra
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

unsigned char *Pixeldata = NULL;
int Stride = 0; // the stride of the Pixeldata
int PixelSize = 0; // the bits per pixel of the Pixeldata

// The function to get the pixel data from the bitmap
static int GetPixel(_envir* e, int xx, int yy, int zz)
{

	if (e == nullptr) return 255;

	const int width = e->X;
	const int height = e->Y;

	// clamp the input xx and yy values
	if (xx >= width)
	{
		xx = width - 1;
	}
	else if (xx < 0)
	{
		xx = 0;
	}

	if (yy >= height)
	{
		yy = height - 1;
	}
	else if (yy < 0)
	{
		yy = 0;
	}

	if (zz < e->Z && Pixeldata != nullptr)
	{
		int val;
		// the source data is BGR(A) the destination is RGB(A)
		ColorBgra* p = reinterpret_cast<ColorBgra*>(Pixeldata + (yy * Stride) + (xx * PixelSize)); // get the pixel at xx,yy

		switch (zz)
		{
		case 0:
			val = p->r; // Red
			break;
		case 1:
			val = p->g; // Green
			break;
		case 2:
			val = p->b; // Blue
			break;
		case 3:
			val = p->a; // Alpha
			break;
		default:
			val = 255;
			break;
		}

		return val;
	}

	return 255; // return 255 if there is an error
}


/*  Setup the source bitmap information
*   this must be called first
*   pixelData is the pointer to the start of the pixel data, Scan0.
*   pixelSize is the number of color channels in the image either 3 or 4 if the image has an alpha channel.
*/
int __stdcall SetupBitmap(unsigned char *pixelData, int width, int height, int stride, int pixelSize)
{
	if (pixelData == nullptr) // return negative value if there is an error
	{
		return -1; // pixeldata is null
	}

	if (width <= 0 || height <= 0)
	{
	   return -2; // invalid width or height
	}

	if (pixelSize < 3 || pixelSize > 4)
	{
		return -3; // the number of channels must be either 3 (RGB) or 4 (RGBA)
	}

	Pixeldata = pixelData;
	Stride = stride;
	PixelSize = pixelSize;

	return 1;
}

// Destroy the source bitmap information.
void __stdcall DestroyBitmap()
{
	// Pixeldata is a pointer to the start of the pixel data in an image owned by the caller.
	// The caller will handle cleaning up its own memory, so just set the pointer to nullptr.
	Pixeldata = nullptr;
	Stride = 0;
	PixelSize = 0;
}

// Creates the filter environment data.
// width is the width of the image in pixels.
// height is the height of the image in pixels.
// pixelSize is the number of channels in the image, 3 for RGB images or 4 if the image has transparency.
// source is the filter source code for the 4 channels
// controlValues is the 8 slider values that can be used by a filter.
FilterEnvironmentData* __stdcall CreateEnvironmentData(const int width, const int height, const int pixelSize, char* source[], int controlValues[])
{
	FilterEnvironmentData* filterData = new(std::nothrow) FilterEnvironmentData();
	if (filterData == nullptr)
	{
		return nullptr;
	}

	filterData->env.X = width;
	filterData->env.Y = height;
	filterData->env.Z = pixelSize; // the max number of channels
	filterData->env.M = static_cast<int>(sqrt(static_cast<double>(width * width) + static_cast<double>(height * height)) / 2.0); // the center of the image
	filterData->env.src = GetPixel;

	for (int i = 0; i < 8; i++)
	{
		filterData->env.value[i] = controlValues[i];
	}

	for (int i = 0; i < 4; i++)
	{
		filterData->tree[i] = ::get_uf_tree(source[i]);
	}

	return filterData;
}

// Frees the filter environment data.
void __stdcall FreeEnvironmentData(FilterEnvironmentData* data)
{
	if (data != nullptr)
	{
		for (int i = 0; i < 4; i++)
		{
			free_tree(data->tree[i]);
		}

		delete data;
	}
}

// Validates the syntax of the specified source code
int __stdcall ValidateSrc(char* src)
{
	int ret = 1;

	s_uf_tree *vt = ::get_uf_tree(src);
	if (vt == nullptr)
	{
		ret = 0;
	}
	free_tree(vt);

	return ret;
}

// Renders the filter to the output surface.
// globalEnvironment is a pointer to the filter environment data.
// rois is a pointer to an array of rectangles that specifies the parts of destination to be modified.
// roisLength is the length of the rois array.
// output is the destination bitmap.
void __stdcall Render(const FilterEnvironmentData* globalEnvironment, const GdipRectangle* rois, const int roisLength, BitmapData* output)
{
	_envir env = globalEnvironment->env;

	unsigned char* scan0 = reinterpret_cast<unsigned char*>(output->scan0);

	for (int i = 0; i < roisLength; i++)
	{
		GdipRectangle roi = rois[i];

		const int top = roi.y;
		const int left = roi.x;
		const int bottom = roi.y + roi.height;
		const int right = roi.x + roi.width;

		for (int y = top; y < bottom; y++)
		{
			ColorBgra* ptr = reinterpret_cast<ColorBgra*>(scan0 + (y * output->stride));
			env.y = y;

			for (int x = left; x < right; x++)
			{
				env.x = x;
				calc_envir(&env);

				for (int i = 0; i < env.Z; i++)
				{
					env.z = i;

					int color = calc(&env, globalEnvironment->tree[i]);

					switch (i)
					{
					case 0:
						ptr->r = color;
						break;
					case 1:
						ptr->g = color;
						break;
					case 2:
						ptr->b = color;
						break;
					case 3:
						ptr->a = color;
						break;
					default:
						break;
					}
				}

				ptr++;
			}
		}
	}
}