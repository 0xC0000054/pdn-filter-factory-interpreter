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



	int DLL_EXPORT __stdcall SetupBitmap(unsigned char* pixelData, int width, int height, int stride, int pixelSize);

	void DLL_EXPORT __stdcall SetControls(int val, int ctl);

	void DLL_EXPORT __stdcall UpdateEnvir(int x, int y);

	int DLL_EXPORT __stdcall ValidateSrc(char* src);

	void DLL_EXPORT __stdcall SetupTree(char* src, int c);

	int DLL_EXPORT __stdcall CalcColor(int c);

	void DLL_EXPORT __stdcall FreeData();

	bool DLL_EXPORT __stdcall datafreed();

#ifdef __cplusplus
}
#endif

_envir *env;
s_uf_tree *tree[4];
unsigned char *Pixeldata = NULL;
int Stride = 0; // the stride of the Pixeldata
int PixelSize = 0; // the bits per pixel of the Pixeldata
bool datafree;

#endif // !FFEVAL_H
