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



	DLL_EXPORT int __stdcall SetupBitmap(unsigned char* pixelData, int width, int height, int stride, int pixelSize);

	DLL_EXPORT void __stdcall SetControls(int val, int ctl);

	DLL_EXPORT void __stdcall UpdateEnvir(int x, int y);

	DLL_EXPORT int __stdcall ValidateSrc(char* src);

	DLL_EXPORT void __stdcall SetupTree(char* src, int c);

	DLL_EXPORT int __stdcall CalcColor(int c);

	DLL_EXPORT void __stdcall FreeData();

	DLL_EXPORT bool __stdcall datafreed();

#ifdef __cplusplus
}
#endif

#endif // !FFEVAL_H
