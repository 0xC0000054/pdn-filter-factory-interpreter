/*
 * Written 1997,2003 Jens Ch. Restemeier <jrestemeier@currantbun.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef _UF_EVAL_H
#define _UF_EVAL_H

struct _envir;

typedef int src_func(struct _envir *e, int xx, int yy, int zz);

typedef struct _envir {
	int storage[256];	/* 256 byte storage for put+get */
	int value[8];		/* 8 int slider-values */
	int r; 			/* red at pixel position */
	int g;			/* green at pixel position */
	int b;			/* blue at pixel position */
	int a;			/* alpha at pixel postion */
	int c;			/* current color (=src(x,y,z)) */
	int i, u, v;		/* color int YUV space */
	int x;			/* x position */
	int y;			/* y position */
	int z;			/* current channel: 0=red, 1= green, 2=blue, 3=alpha */
	int X;			/* X-width of image */
	int Y;			/* Y-width of image */
	int Z;			/* number of channels of image */
	int d;			/* direction from center of the pic (-512 to 512) */
	int m;			/* distance to center of the pic */
	int M;			/* maximum distance from the center */
	src_func *src;		/* function to get pixel-information */
} _envir;

#ifdef __cplusplus
extern "C" {
#endif

void calc_envir(_envir *e);
int calc(_envir *e, s_uf_tree *t);

#ifdef __cplusplus
}
#endif

#endif
