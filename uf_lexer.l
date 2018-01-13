%{
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
#include <string.h>
#include <ctype.h>

#include "uf_interface.h"
#include "uf_parser.h"

int depth;
%}

HEX [0-9a-fA-F]
%%

"&&"	return t_and;
"||"	return t_or;
"=="	return t_eq;
"!="	return t_neq;
"<="	return t_le;
">="	return t_be;
"<<"	return t_shl;
">>"	return t_shr;

"rmin"	return t_rmin;
"gmin"	return t_gmin;
"bmin"	return t_bmin;
"amin"	return t_amin;
"cmin"	return t_cmin;
"imin"	return t_imin;
"umin"	return t_umin;
"vmin"	return t_vmin;
"pmin"	return t_pmin;
"tmin"	return t_tmin;
"dmin"	return t_dmin;
"mmin"	return t_mmin;
"xmin"	return t_xmin;
"ymin"	return t_ymin;
"zmin"	return t_zmin;

"rmax"	return t_rmax;
"gmax"	return t_gmax;
"bmax"	return t_bmax;
"amax"	return t_amax;
"cmax"	return t_cmax;
"imax"	return t_imax;
"umax"	return t_umax;
"vmax"	return t_vmax;
"pmax"	return t_pmax;
"tmax"	return t_tmax;
"dmax"	return t_dmax;
"mmax"	return t_mmax;
"xmax"	return t_xmax;
"ymax"	return t_ymax;
"zmax"	return t_zmax;

"abs"	return t_abs;
"add"	return t_add;
"cnv"	return t_cnv;
"ctl"	return t_ctl;
"dif"	return t_dif;
"get"	return t_get;
"put"	return t_put;
"map"	return t_map;
"max"	return t_max;
"min"	return t_min;
"mix"	return t_mix;
"rnd"	return t_rnd;
"scl"	return t_scl;
"sqr"	return t_sqr;
"src"	return t_src;
"sub"	return t_sub;
"val"	return t_val;
"c2d"	return t_c2d;
"c2m"	return t_c2m;
"cos"	return t_cos;
"r2x"	return t_r2x;
"r2y"	return t_r2y;
"rad"	return t_rad;
"rst"	return t_rst;
"sin"	return t_sin;
"tan"	return t_tan;

[\r\n\t" "]	/* ignore NL/CR/TAB/SPACE */

[0-9]+  {
		yylval=malloc(sizeof(s_uf_tree));
		yylval->op_type=v_int;
		yylval->value=atoi(yytext); 
		yylval->nodes=NULL;
		return v_int; 
	}
0[xX]{HEX}+ {
		yylval=malloc(sizeof(s_uf_tree));
		yylval->op_type=v_int;
		yylval->value=strtol(yytext,NULL,0); 
		yylval->nodes=NULL;
		return v_int; 
	}

"("	{ depth++; return yytext[0]; }
")"	{ 
		if (depth>0) depth--; 
		if (depth<0) 
			return t_error; 
		else 
			return yytext[0]; }
","	{ if (depth>0) return yytext[0]; else return t_comma; }
<<EOF>> return t_end_of_string;
.	return yytext[0];

%%

void do_parse(char *s)  
{
        YY_BUFFER_STATE yy_buffer_state;
	depth=0;
        yy_buffer_state=yy_scan_string(s);
        yyparse();
        yy_delete_buffer(yy_buffer_state);
}
