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
		int rgba[4];
		// the source data is BGR(A) the destination is RGB(A)
		unsigned char *p = (unsigned char*)Pixeldata + (yy * Stride) + (xx * PixelSize); // get the pixel at xx,yy
		rgba[0] = (int)p[2]; // Red
		rgba[1] = (int)p[1]; // Green
		rgba[2] = (int)p[0]; // Blue

		if (e->Z == 4)
		{
			rgba[3] = (int)p[3]; // Alpha
		}
		else
		{
			rgba[3] = 255;
		}
		int val = rgba[zz];
		return val;
	}

	return 255; // return 255 if there is an error
}


/*  Setup the source bitmap information and sets the _envir data
*   this must be called first
*   pixelData is the pointer to the start of the pixel data, Scan0.
*   pixelSize is the number of color channels in the image either 3 or 4 if the image has an alpha channel.
*/
int __stdcall SetupBitmap(unsigned char *pixelData, int width, int height, int stride, int pixelSize)
{
	if (!datafree)
	{
		FreeData(); // make sure the data has been freed
	}

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

	env = new(std::nothrow) _envir;
	if (env == nullptr)
	{
		return -4; // unable to create a new _envir, out of memory?
	}

	env->X = width;
	env->Y = height;
	env->Z = pixelSize; // the max number of channels
	env->M = static_cast<int>(sqrt(static_cast<double>(env->X * env->X) + static_cast<double>(env->Y *env->Y)) / 2.0); // the center of the image
	env->src = GetPixel;

	datafree = false;

	return 1;
}

// set the value for the eight sliders
void __stdcall SetControls(int val, int ctl)
{
	if (!datafree)
	{
		env->value[ctl] = val;
	}
}

// parse the filter source into the tree
void __stdcall SetupTree(char* src,int c)
{
	if (!datafree)
	{
		tree[c] = ::get_uf_tree(src);
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

bool __stdcall datafreed()
{
	return datafree;
}

// Update the pixel position to (x,y) and recalculate the environment
void __stdcall UpdateEnvir(int x, int y)
{
	if (!datafree)
	{
		env->x = x;
		env->y = y;
		calc_envir(env); // update the envir data
	}
}

// Calculate the pixel color for the specified channel, the channels are in RGBA order
int __stdcall CalcColor(int c)
{

	if (c < env->Z && !datafree)
	{
		env->z = c;
		int ret = calc(env, tree[c]); // calculate the resulting color
		return ret;
	}
	else
	{
		return 255;
	}
}

// Frees the data and cleans up
void __stdcall FreeData()
{
	if (env != nullptr)
	{
		delete env;
		env = nullptr;
	}

	for (int i = 0; i < 4; i++)
	{
		free_tree(tree[i]); // free the parse tree
	}

	if (Pixeldata != nullptr)
	{
		Pixeldata = nullptr; /* set the Pixeldata pointer to nullptr,
							 the parent application will handle cleaning up it's own memory */
	}

	datafree = true;
}
