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

#ifndef FFEVAL_H
#define FFEVAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "uf_interface.h"
#include "uf_eval.h"

#define DLL_EXPORT __declspec(dllexport)

	struct FilterEnvironmentData
	{
		_envir env;
		s_uf_tree* tree[4];
	};

	struct BitmapData
	{
		int width;
		int height;
		int stride;
		int pixelSize;
		void* scan0;
	};

	struct GdipRectangle
	{
		int x;
		int y;
		int width;
		int height;
	};

	DLL_EXPORT int __stdcall SetupBitmap(unsigned char* pixelData, int width, int height, int stride, int pixelSize);

	DLL_EXPORT void __stdcall DestroyBitmap();

	DLL_EXPORT FilterEnvironmentData* __stdcall CreateEnvironmentData(const int width, const int height, const int pixelSize, char* source[], int controlValues[]);

	DLL_EXPORT void __stdcall FreeEnvironmentData(FilterEnvironmentData* data);

	DLL_EXPORT int __stdcall ValidateSrc(char* src);

	DLL_EXPORT void __stdcall Render(const FilterEnvironmentData* globalEnvironment, const GdipRectangle* rois, const int roisLength, BitmapData* output);

#ifdef __cplusplus
}
#endif

#endif // !FFEVAL_H
