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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <time.h>
#include <ctype.h>

#include "uf_interface.h"
#include "uf_eval.h"
#include "uf_parser.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/*
 * This is a little unsusual: Normally you'll create a sinus-tab, and do
 * a cosinus by adding an offset.
 * But this should be the easiest way to allow negative parameters: As
 * cosinus is symmetric at x=0 ( cos(x)==cos(-x) ) I can use an abs(x).
 *
 * Thanks to Michael Johannhanwahr for these tables:
 */

int cos_tab[1024] = {
	 512,     511,     511,     511,     511,     511,     511,     511,
	 511,     511,     511,     510,     510,     510,     510,     509,
	 509,     509,     508,     508,     508,     507,     507,     506,
	 506,     505,     505,     504,     504,     503,     503,     502,
	 502,     501,     500,     500,     499,     498,     498,     497,
	 496,     495,     495,     494,     493,     492,     491,     490,
	 489,     489,     488,     487,     486,     485,     484,     483,
	 482,     481,     479,     478,     477,     476,     475,     474,
	 473,     471,     470,     469,     468,     466,     465,     464,
	 462,     461,     460,     458,     457,     455,     454,     453,
	 451,     450,     448,     447,     445,     443,     442,     440,
	 439,     437,     435,     434,     432,     430,     429,     427,
	 425,     423,     422,     420,     418,     416,     414,     413,
	 411,     409,     407,     405,     403,     401,     399,     397,
	 395,     393,     391,     389,     387,     385,     383,     381,
	 379,     377,     375,     372,     370,     368,     366,     364,
	 362,     359,     357,     355,     353,     350,     348,     346,
	 343,     341,     339,     336,     334,     332,     329,     327,
	 324,     322,     319,     317,     315,     312,     310,     307,
	 305,     302,     299,     297,     294,     292,     289,     287,
	 284,     281,     279,     276,     273,     271,     268,     265,
	 263,     260,     257,     255,     252,     249,     246,     244,
	 241,     238,     235,     233,     230,     227,     224,     221,
	 218,     216,     213,     210,     207,     204,     201,     198,
	 195,     193,     190,     187,     184,     181,     178,     175,
	 172,     169,     166,     163,     160,     157,     154,     151,
	 148,     145,     142,     139,     136,     133,     130,     127,
	 124,     121,     118,     115,     112,     109,     106,     102,
	  99,      96,      93,      90,      87,      84,      81,      78,
	  75,      72,      68,      65,      62,      59,      56,      53,
	  50,      47,      43,      40,      37,      34,      31,      28,
	  25,      21,      18,      15,      12,       9,       6,       3,
	  -4,      -7,     -10,     -13,     -16,     -19,     -22,     -26,
	 -29,     -32,     -35,     -38,     -41,     -44,     -48,     -51,
	 -54,     -57,     -60,     -63,     -66,     -69,     -72,     -76,
	 -79,     -82,     -85,     -88,     -91,     -94,     -97,    -100,
	-103,    -107,    -110,    -113,    -116,    -119,    -122,    -125,
	-128,    -131,    -134,    -137,    -140,    -143,    -146,    -149,
	-152,    -155,    -158,    -161,    -164,    -167,    -170,    -173,
	-176,    -179,    -182,    -185,    -188,    -191,    -193,    -196,
	-199,    -202,    -205,    -208,    -211,    -214,    -217,    -219,
	-222,    -225,    -228,    -231,    -233,    -236,    -239,    -242,
	-245,    -247,    -250,    -253,    -256,    -258,    -261,    -264,
	-266,    -269,    -272,    -274,    -277,    -280,    -282,    -285,
	-288,    -290,    -293,    -295,    -298,    -300,    -303,    -305,
	-308,    -310,    -313,    -315,    -318,    -320,    -323,    -325,
	-328,    -330,    -333,    -335,    -337,    -340,    -342,    -344,
	-347,    -349,    -351,    -354,    -356,    -358,    -360,    -363,
	-365,    -367,    -369,    -371,    -373,    -376,    -378,    -380,
	-382,    -384,    -386,    -388,    -390,    -392,    -394,    -396,
	-398,    -400,    -402,    -404,    -406,    -408,    -410,    -412,
	-414,    -415,    -417,    -419,    -421,    -423,    -424,    -426,
	-428,    -430,    -431,    -433,    -435,    -436,    -438,    -440,
	-441,    -443,    -444,    -446,    -447,    -449,    -451,    -452,
	-453,    -455,    -456,    -458,    -459,    -461,    -462,    -463,
	-465,    -466,    -467,    -469,    -470,    -471,    -472,    -473,
	-475,    -476,    -477,    -478,    -479,    -480,    -481,    -483,
	-484,    -485,    -486,    -487,    -488,    -489,    -490,    -490,
	-491,    -492,    -493,    -494,    -495,    -496,    -496,    -497,
	-498,    -499,    -499,    -500,    -501,    -501,    -502,    -503,
	-503,    -504,    -504,    -505,    -505,    -506,    -506,    -507,
	-507,    -508,    -508,    -509,    -509,    -509,    -510,    -510,
	-510,    -511,    -511,    -511,    -511,    -512,    -512,    -512,
	-512,    -512,    -512,    -512,    -512,    -512,    -512,    -512,
	-512,    -512,    -512,    -512,    -512,    -512,    -512,    -512,
	-512,    -512,    -512,    -511,    -511,    -511,    -511,    -510,
	-510,    -510,    -509,    -509,    -509,    -508,    -508,    -507,
	-507,    -506,    -506,    -505,    -505,    -504,    -504,    -503,
	-503,    -502,    -501,    -501,    -500,    -499,    -499,    -498,
	-497,    -496,    -496,    -495,    -494,    -493,    -492,    -491,
	-490,    -490,    -489,    -488,    -487,    -486,    -485,    -484,
	-483,    -481,    -480,    -479,    -478,    -477,    -476,    -475,
	-473,    -472,    -471,    -470,    -469,    -467,    -466,    -465,
	-463,    -462,    -461,    -459,    -458,    -456,    -455,    -453,
	-452,    -451,    -449,    -447,    -446,    -444,    -443,    -441,
	-440,    -438,    -436,    -435,    -433,    -431,    -430,    -428,
	-426,    -424,    -423,    -421,    -419,    -417,    -415,    -414,
	-412,    -410,    -408,    -406,    -404,    -402,    -400,    -398,
	-396,    -394,    -392,    -390,    -388,    -386,    -384,    -382,
	-380,    -378,    -376,    -373,    -371,    -369,    -367,    -365,
	-363,    -360,    -358,    -356,    -354,    -351,    -349,    -347,
	-344,    -342,    -340,    -337,    -335,    -333,    -330,    -328,
	-325,    -323,    -320,    -318,    -315,    -313,    -310,    -308,
	-305,    -303,    -300,    -298,    -295,    -293,    -290,    -288,
	-285,    -282,    -280,    -277,    -274,    -272,    -269,    -266,
	-264,    -261,    -258,    -256,    -253,    -250,    -247,    -245,
	-242,    -239,    -236,    -233,    -231,    -228,    -225,    -222,
	-219,    -217,    -214,    -211,    -208,    -205,    -202,    -199,
	-196,    -193,    -191,    -188,    -185,    -182,    -179,    -176,
	-173,    -170,    -167,    -164,    -161,    -158,    -155,    -152,
	-149,    -146,    -143,    -140,    -137,    -134,    -131,    -128,
	-125,    -122,    -119,    -116,    -113,    -110,    -107,    -103,
	-100,     -97,     -94,     -91,     -88,     -85,     -82,     -79,
	 -76,     -72,     -69,     -66,     -63,     -60,     -57,     -54,
	 -51,     -48,     -44,     -41,     -38,     -35,     -32,     -29,
	 -26,     -22,     -19,     -16,     -13,     -10,      -7,      -4,
	   3,       6,       9,      12,      15,      18,      21,      25,
	  28,      31,      34,      37,      40,      43,      47,      50,
	  53,      56,      59,      62,      65,      68,      72,      75,
	  78,      81,      84,      87,      90,      93,      96,      99,
	 102,     106,     109,     112,     115,     118,     121,     124,
	 127,     130,     133,     136,     139,     142,     145,     148,
	 151,     154,     157,     160,     163,     166,     169,     172,
	 175,     178,     181,     184,     187,     190,     193,     195,
	 198,     201,     204,     207,     210,     213,     216,     218,
	 221,     224,     227,     230,     233,     235,     238,     241,
	 244,     246,     249,     252,     255,     257,     260,     263,
	 265,     268,     271,     273,     276,     279,     281,     284,
	 287,     289,     292,     294,     297,     299,     302,     305,
	 307,     310,     312,     315,     317,     319,     322,     324,
	 327,     329,     332,     334,     336,     339,     341,     343,
	 346,     348,     350,     353,     355,     357,     359,     362,
	 364,     366,     368,     370,     372,     375,     377,     379,
	 381,     383,     385,     387,     389,     391,     393,     395,
	 397,     399,     401,     403,     405,     407,     409,     411,
	 413,     414,     416,     418,     420,     422,     423,     425,
	 427,     429,     430,     432,     434,     435,     437,     439,
	 440,     442,     443,     445,     447,     448,     450,     451,
	 453,     454,     455,     457,     458,     460,     461,     462,
	 464,     465,     466,     468,     469,     470,     471,     473,
	 474,     475,     476,     477,     478,     479,     481,     482,
	 483,     484,     485,     486,     487,     488,     489,     489,
	 490,     491,     492,     493,     494,     495,     495,     496,
	 497,     498,     498,     499,     500,     500,     501,     502,
	 502,     503,     503,     504,     504,     505,     505,     506,
	 506,     507,     507,     508,     508,     508,     509,     509,
	 509,     510,     510,     510,     510,     511,     511,     511,
	 511,     511,     511,     511,     511,     511,     511,     512
};

int tan_tab[512] = {
	  -6,       6,      12,      18,      25,      31,      37,      43,
	  50,      56,      62,      69,      75,      81,      88,      94,
	 100,     107,     113,     119,     126,     132,     139,     145,
	 151,     158,     164,     171,     177,     184,     190,     197,
	 203,     210,     216,     223,     229,     236,     243,     249,
	 256,     263,     269,     276,     283,     290,     296,     303,
	 310,     317,     324,     331,     338,     345,     352,     359,
	 366,     373,     380,     387,     394,     402,     409,     416,
	 424,     431,     438,     446,     453,     461,     468,     476,
	 484,     492,     499,     507,     515,     523,     531,     539,
	 547,     555,     563,     571,     580,     588,     596,     605,
	 613,     622,     631,     639,     648,     657,     666,     675,
	 684,     693,     702,     711,     721,     730,     740,     749,
	 759,     769,     779,     789,     799,     809,     819,     829,
	 840,     850,     861,     872,     883,     894,     905,     916,
	 928,     939,     951,     962,     974,     987,     999,    1011,
	1024,    1036,    1049,    1062,    1075,    1088,    1102,    1115,
	1129,    1143,    1157,    1172,    1187,    1201,    1216,    1232,
	1247,    1263,    1279,    1295,    1312,    1328,    1345,    1363,
	1380,    1398,    1416,    1435,    1453,    1473,    1492,    1512,
	1532,    1553,    1574,    1595,    1617,    1639,    1661,    1684,
	1708,    1732,    1756,    1781,    1807,    1833,    1860,    1887,
	1915,    1944,    1973,    2003,    2034,    2065,    2098,    2130,
	2165,    2199,    2235,    2272,    2310,    2348,    2388,    2430,
	2471,    2516,    2560,    2606,    2654,    2704,    2755,    2807,
	2862,    2918,    2976,    3037,    3099,    3165,    3232,    3302,
	3375,    3452,    3531,    3614,    3700,    3790,    3885,    3984,
	4088,    4197,    4312,    4433,    4560,    4695,    4837,    4987,
	5148,    5319,    5501,    5693,    5901,    6123,    6365,    6623,
	6903,    7209,    7539,    7904,    8304,    8746,    9233,    9780,
   10396,   11100,   11896,   12814,   13884,   15147,   16678,   18530,
   20841,   23841,   27802,   33404,   41721,   55728,   83458,  167761,
 -167772,  -83463,  -55731,  -41726,  -33410,  -27809,  -23847,  -20846,
  -18536,  -16684,  -15154,  -13890,  -12820,  -11902,  -11106,  -10401,
   -9786,   -9238,   -8753,   -8310,   -7909,   -7545,   -7215,   -6909,
   -6630,   -6371,   -6129,   -5907,   -5699,   -5507,   -5325,   -5154,
   -4993,   -4843,   -4701,   -4567,   -4439,   -4318,   -4203,   -4094,
   -3990,   -3891,   -3796,   -3707,   -3620,   -3537,   -3458,   -3381,
   -3308,   -3238,   -3171,   -3106,   -3043,   -2983,   -2924,   -2868,
   -2813,   -2761,   -2710,   -2661,   -2613,   -2566,   -2522,   -2478,
   -2436,   -2395,   -2355,   -2316,   -2278,   -2242,   -2206,   -2171,
   -2137,   -2104,   -2072,   -2040,   -2009,   -1980,   -1950,   -1922,
   -1893,   -1866,   -1839,   -1813,   -1788,   -1763,   -1738,   -1714,
   -1691,   -1668,   -1645,   -1623,   -1601,   -1580,   -1559,   -1538,
   -1518,   -1498,   -1479,   -1460,   -1441,   -1423,   -1404,   -1386,
   -1369,   -1352,   -1335,   -1318,   -1301,   -1285,   -1269,   -1253,
   -1238,   -1223,   -1208,   -1193,   -1178,   -1164,   -1150,   -1136,
   -1122,   -1108,   -1095,   -1081,   -1068,   -1055,   -1042,   -1030,
   -1017,   -1005,    -993,    -981,    -969,    -957,    -945,    -934,
	-923,    -911,    -900,    -889,    -878,    -867,    -857,    -846,
	-836,    -825,    -815,    -805,    -795,    -785,    -775,    -765,
	-756,    -746,    -736,    -727,    -718,    -708,    -699,    -690,
	-681,    -672,    -663,    -654,    -645,    -637,    -628,    -620,
	-611,    -603,    -594,    -586,    -578,    -569,    -561,    -553,
	-545,    -537,    -529,    -521,    -513,    -506,    -498,    -490,
	-482,    -475,    -467,    -460,    -452,    -445,    -437,    -430,
	-423,    -415,    -408,    -401,    -394,    -386,    -379,    -372,
	-365,    -358,    -351,    -344,    -337,    -330,    -323,    -316,
	-310,    -303,    -296,    -289,    -282,    -276,    -269,    -262,
	-256,    -249,    -242,    -236,    -229,    -223,    -216,    -209,
	-203,    -196,    -190,    -183,    -177,    -171,    -164,    -158,
	-151,    -145,    -138,    -132,    -126,    -119,    -113,    -107,
	-100,     -94,     -88,     -81,     -75,     -69,     -62,     -56,
	 -50,     -43,     -37,     -31,     -25,     -18,     -12,      -6
};

inline int (p_src(_envir *e, int x, int y, int z));
inline int (p_rad(_envir *e, int d, int m, int z));
inline int (p_rad(_envir *e, int d, int m, int z));
inline int (p_val(_envir *e, int i, int a, int b));
inline int (p_ctl(_envir *e, int i));
inline int (p_dif(_envir *e, int a, int b));
inline int (p_put(_envir *e, int v, int i));
inline int (p_map(_envir *e, int a, int b));
inline int (p_get(_envir *e, int i));
inline int (p_sin(_envir *e, int i));
inline int (p_cos(_envir *e, int i));
inline int (p_tan(_envir *e, int i));
inline int (p_sqr(_envir *e, int i));
inline int (p_cnv(_envir *e, int m11, int m12, int m13, int m21, int m22, int m23, int m31, int m32, int m33, int d));
inline int (p_div(_envir *e, int a, int b));
inline int (p_mod(_envir *e, int a, int b));
inline int (p_abs(_envir *e, int a));
inline int (p_rnd(_envir *e, int a, int b));
inline int (p_min(_envir *e, int a, int b));
inline int (p_max(_envir *e, int a, int b));
inline int (p_scl(_envir *e, int a, int il, int ih, int ol, int oh));
inline int (p_add(_envir *e, int a, int b, int c));
inline int (p_mix(_envir *e, int a, int b, int n, int d));
inline int (p_sub(_envir *e, int a, int b, int c));
inline int (p_c2d(_envir *e, int x, int y));
inline int (p_c2m(_envir *e, int x, int y));
inline int (p_r2x(_envir *e, int d, int m));
inline int (p_r2y(_envir *e, int d, int m));

s_uf_tree *f;
#define CT(x) calc_tree(e, f->nodes[x])

int calc_tree(_envir *e, s_uf_tree *f)
{
	if (e==NULL || f==NULL) return 0;
	switch (f->op_type) {
		case v_int: return f->value;
		case '+': return CT(0) + CT(1);
		case '-': return CT(0) - CT(1);
		case '*': return CT(0) * CT(1);
		case t_and: return CT(0) && CT(1);
		case t_or: return CT(0) || CT(1);
		case t_eq: return CT(0) == CT(1);
		case t_neq: return CT(0) != CT(1);
		case '<': return CT(0) < CT(1);
		case t_le: return CT(0) <= CT(1);
		case '>': return CT(0) > CT(1);
		case t_be: return CT(0) >= CT(1);
		case '&': return CT(0) & CT(1);
		case '|': return CT(0) | CT(1);
		case '^': return CT(0) ^ CT(1);
		case t_shl: return CT(0) << CT(1);
		case t_shr: return CT(0) >> CT(1);
		case '~': return ~CT(0);
		case 'r': return e->r;
		case 'g': return e->g;
		case 'b': return e->b;
		case 'a': return e->a;
		case 'c': return e->c;
		case 'i': return e->i;
		case 'u': return e->u;
		case 'v': return e->v;
		case 'x': return e->x;
		case 'y': return e->y;
		case 'z': return e->z;
		case 'd': return e->d;
		case 'm': return e->m;
		case t_xmax: return e->X;
		case t_ymax: return e->Y;
		case t_zmax: return e->Z;
		case t_mmax: return e->M;
		case '!': return !CT(0);
		case t_sin: return p_sin(e, CT(0));
		case t_cos: return p_cos(e, CT(0));
		case t_tan: return p_tan(e, CT(0));
		case t_sqr: return p_sqr(e, CT(0));
		case t_ctl: return p_ctl(e, CT(0));
		case t_get: return p_get(e, CT(0));
		case t_abs: return p_abs(e, CT(0));
		case t_c2d: return p_c2d(e, CT(0), CT(1));
		case t_c2m: return p_c2m(e, CT(0), CT(1));
		case t_r2x: return p_r2x(e, CT(0), CT(1));
		case t_r2y: return p_r2y(e, CT(0), CT(1));
		case '/': return p_div(e, CT(0), CT(1));
		case '%': return p_mod(e, CT(0), CT(1));
		case t_put: return p_put(e, CT(0), CT(1));
		case t_map: return p_map(e, CT(0), CT(1));
		case t_add: return p_add(e, CT(0), CT(1), CT(2));
		case t_mix: return p_mix(e, CT(0), CT(1), CT(2), CT(3));
		case t_sub: return p_sub(e, CT(0), CT(1), CT(2));
		case t_min: return p_min(e, CT(0), CT(1));
		case t_max: return p_max(e, CT(0), CT(1));
		case t_rnd: return p_rnd(e, CT(0), CT(1));
		case t_dif: return p_dif(e, CT(0), CT(1));
		case t_val: return p_val(e, CT(0), CT(1), CT(2));
		case t_src: return p_src(e, CT(0), CT(1), CT(2));
		case t_rad: return p_rad(e, CT(0), CT(1), CT(2));
		case '?': {
			int a,b,c;
			a=CT(0); b=CT(1); c=CT(2);
			return a ? b : c;
		}
		case t_scl: return p_scl(e, CT(0), CT(1), CT(2), CT(3), CT(4));
		case t_cnv: return p_cnv(e,
				CT(0), CT(1), CT(2),
				CT(3), CT(4), CT(5),
				CT(6), CT(7), CT(8),
				CT(9));
		case t_comma : {
			CT(0);
			return CT(1);
		}
	}
	fprintf(stderr, "unhandled operator %i !\n", f->op_type);
	return 0;
}

/* calculate all pixel-relative information of the envir */
void calc_envir(_envir *e)
{
	if (e==NULL) return;
	e->d=p_c2d(e, (e->X>>1)-e->x, (e->Y>>1)-e->y);
	e->m=p_c2m(e, (e->X>>1)-e->x, (e->Y>>1)-e->y);
	e->r=p_src(e, e->x,e->y,0);
	e->g=p_src(e, e->x,e->y,1);
	e->b=p_src(e, e->x,e->y,2);
	e->a=p_src(e, e->x,e->y,3);
	e->i=((76*e->r)+(150*e->g)+(29*e->b))/256;
	e->u=((-19*e->r)+(-37*e->g)+(56*e->b))/256;
	e->v=((78*e->r)+(-65*e->g)+(-13*e->b))/256;
}

int calc(_envir *e, s_uf_tree *t)
{
	int v;
	/* prepare channel-specific values of envir */
	e->c=p_src(e, e->x, e->y, e->z);

	v=calc_tree(e, t);

	/* scale */
	if (v<0) return 0;
	if (v>255) return 255;
	return v;
}

/* src(x,y,z) Channel z for the pixel at coordinates x,y */
inline int p_src(_envir *e, int xx, int yy, int zz)
{
	if (zz < e->Z) {
		return e->src((struct _envir *)e, xx, yy, zz);
	} else {
		return 255;
	}
}

/* rad(d,m,z) Channel z in the source image, which is m units away, at an
   angle of d, from the center of the image */
inline int p_rad(_envir *e, int dd, int mm, int zz)
{
	return p_src(e, (e->X/2)-p_r2x(e,dd,mm), (e->Y/2)-p_r2y(e,dd,mm), zz);
}

// cnv(m11,m12,m13,m21,m22,m23,m31,m32,m33,d)  Convolution matrix function
inline int p_cnv(_envir *e, int m11, int m12, int m13, int m21, int m22, int m23, int m31, int m32, int m33, int dd)
{
	if (dd==0) return 255;
	return (m11*p_src(e, e->x-1,e->y-1, e->z) + m12*p_src(e, e->x,e->y-1,e->z) + m13*p_src(e, e->x+1,e->y-1,e->z) +
			m21*p_src(e, e->x-1,e->y  , e->z) + m22*p_src(e, e->x,e->y  ,e->z) + m23*p_src(e, e->x+1,e->y  ,e->z) +
			m31*p_src(e, e->x-1,e->y+1, e->z) + m32*p_src(e, e->x,e->y+1,e->z) + m33*p_src(e, e->x+1,e->y+1,e->z)) / dd;
}

/* ctl(i) Value of slider i, where i is an integer between 0 and 7, inclusive */
inline int p_ctl(_envir *e, int i)
{
	if ((i<0) || (i>7)) return 0;
	return e->value[i];
}

/* val(i,a,b) Value of slider i, mapped onto the range a to b */
inline int p_val(_envir *e, int i, int a, int b)
{
	return ((p_ctl(e,i)*(b-a))/255)+a;
}

/* dif(a,b) Absolute value of the difference of a and b */
inline int p_dif(_envir *e, int a, int b)
{
	return abs(a-b);
}

/* put(v,i) Puts the new value v into cell i */
inline int p_put(_envir *e, int v, int i)
{
	if ((i<0) || (i>255)) return 0;
	e->storage[i]=v;
	return v;
}

/* get(i) Returns the current cell value at i */
inline int p_get(_envir *e, int i)
{
	if ((i<0) || (i>255)) return 0;
	return e->storage[i];
}

/* sin(x) Sine function of x, where x is an integer between 0 and
	1024, inclusive, and the value returned is an integer
	between -512 and 512, inclusive (Windows) or -1024 and
	1024, inclusive (Mac OS) */
inline int p_sin(_envir *e, int i)
{
	return p_cos(e, i-256);
}

/* cos(x) Cosine function of x, where x is an integer between 0 and
1024, inclusive, and the value returned is an integer
between -512 and 512, inclusive (Windows) or -1024 and
1024, inclusive (Mac OS)*/
inline int p_cos(_envir *e, int i)
{
	return cos_tab[abs(i) & 1023];
}


/* tan(x)
	Bounded tangent function of x, where x is an integer
	between -256 and 256, inclusive, and the value returned is
	an integer between -512 and 512, inclusive (Windows) or
	-1024 and 1024, inclusive (Mac OS)
	 */
inline int p_tan(_envir *e, int i)
{
	return tan_tab[(i+256) & 511];
}

/* sqr(x) Square root of x */
inline int p_sqr(_envir *e, int i)
{
	return (i>0) ? (int)sqrt(static_cast<double>(i)) : 0;
}

/* Division function */
inline int p_div(_envir *e, int a, int b)
{
	return (b!=0) ? a / b : 1;
}

/* Modulus function */
inline int p_mod(_envir *e, int a, int b)
{
	return (b!=0) ? a % b : 0;
}

/* abs(a) Absolute value of a */
inline int p_abs(_envir *e, int a)
{
	return (a>0) ? a : -a;
}

/* min(a,b) Lesser of a and b */
inline int p_min(_envir *e, int a, int b)
{
	return (a<b) ? a : b;
}

/* max(a,b) Greater of a and b */
inline int p_max(_envir *e, int a, int b)
{
	return (a>b) ? a : b;
}

/* rnd(a,b) Random number between a and b, inclusive */
inline int p_rnd(_envir *e, int a, int b)
{
	return (a!=b) ? (rand() % (b-a)) + a : a;
}

// scl(a,il,ih,ol,oh) Scale a from input range (il to ih) to output range (ol to oh)
inline int p_scl(_envir *e, int a, int il, int ih, int ol, int oh)
{
	return (ih!=il) ? (((a-il)*(oh-ol))/(ih-il))+ol : 0;
}

/* map(i,n) Item n from mapping table i, where i is an integer between
0 and 3, inclusive, and n is and integer between 0 and 255,
inclusive */
inline int p_map(_envir *e, int i, int n)
{
	int x,y;
	x=p_ctl(e, i*2); y=p_ctl(e, i*2+1);
	return abs((n*(y-x) / 255)+x);
}

/* add(a,b,c) Sum of a and b, or c, whichever is lesser */
inline int p_add(_envir *e, int a, int b, int c)
{
	return p_min(e, a+b, c);
}

/* mix(a,b,n,d) Mixture of a and b by fraction n/d, a*n/d+b*(d-n)/d */
inline int p_mix(_envir *e, int a, int b, int n, int d)
{
	return (d!=0) ? a*n/d+b*(d-n)/d : 0;
}

/* sub(a,b,c) Difference of a and b, or c, whichever is greater */
inline int p_sub(_envir *e, int a, int b, int c)
{
	return p_max(e, p_dif(e,a,b), c);
}

/* c2d(x,y) Angle displacement of the pixel at coordinates x,y */
inline int p_c2d(_envir *e, int x, int y)
{
	/*
   *  This has been taken from Filter Foundry,
   *  http://www.telegraphics.com.au/sw/info/filterfoundry.html
   *  (Code released under GPL)
   */
   return (int)(atan2(static_cast<double>(-y), static_cast<double>(-x)) * (512 / M_PI));
}

/* c2m(x,y) Magnitude displacement of the pixel at coordinates x,y */
inline int p_c2m(_envir *e, int x, int y)
{
	return (int)sqrt(static_cast<double>(x*x+y*y));
}

/* r2x(d,m) x displacement of the pixel m units away, at an angle of d,
   from an arbitrary center */
inline int p_r2x(_envir *e, int dd, int mm)
{
	return static_cast<int>(cos(M_PI * (float)dd / 512.0 )*(float)mm);
}


/* r2y(d,m) y displacement of the pixel m units away, at an angle of d,
   from an arbitrary center */
inline int p_r2y(_envir *e, int dd, int mm)
{
	return static_cast<int>(sin(M_PI * (float)dd / 512.0 )*(float)mm);
}
