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
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "uf_interface.h"

#define YYSTYPE s_uf_tree *

s_uf_tree *uf_root;

int yyerror(char *s)
{
	fprintf(stderr, "%s\n", s);
	return 0;
}

s_uf_tree *get_uf_tree(char *s)
{
	do_parse(s);
	return uf_root;
}

void free_tree(s_uf_tree *a)
{
	int i;
	if (a==NULL) return;
	if (a->op_type==v_int) return;
	for (i=0; i<a->value; i++) {
		free_tree(a->nodes[i]);
	}
	free(a->nodes);
	free(a);
	return;
}
%}

%left t_comma

%right '?' ':'

%right t_abs
%right t_add
%right t_cnv
%right t_ctl
%right t_dif
%right t_get
%right t_put
%right t_map
%right t_max
%right t_min
%right t_mix
%right t_rnd
%right t_scl
%right t_sqr
%right t_src
%right t_sub
%right t_val
%right t_c2d
%right t_c2m
%right t_cos
%right t_r2x
%right t_r2y
%right t_rad
%right t_rst
%right t_sin
%right t_tan

%left '&' '|' '^'
%right t_and
%right t_or
%right t_eq
%right t_neq
%right t_shl
%right t_shr

%left '<' '>' t_le t_be
%left '+' '-'
%left '*' '/' '%'
%left ','
%token '(' ')'

%left t_sign '!' '~'

%token 'r' 'g' 'b' 'a' 'c' 'x' 'y' 'X' 'Y' 'i' 'u' 'v' 'z' 'Z' 'd' 'D' 'm' 'M' 
%token t_rmin t_gmin t_bmin t_amin t_cmin t_imin t_umin t_vmin t_pmin t_tmin t_dmin t_mmin t_xmin t_ymin t_zmin
%token t_rmax t_gmax t_bmax t_amax t_cmax t_imax t_umax t_vmax t_pmax t_tmax t_dmax t_mmax t_xmax t_ymax t_zmax

%token v_int
%token t_end_of_string t_error

%%

/****************************************************************************/

input:  { 
		uf_root=NULL; 
		YYABORT; 
	}
	| exp t_end_of_string {
		if (depth==0) {
			uf_root=$1;
		} else {
			free_tree($1);
			if (depth<0) 
				fprintf(stderr, "too many ')' !\n");
			else
				fprintf(stderr, "')' missing !\n");
			uf_root=NULL;
		}
		YYACCEPT;
	}
	| error { 
		yyerrok;
		uf_root=NULL; 
		YYABORT; 
	}
	;


exp:    v_int			{ $$ = $1; }
	| 'r' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='r';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'g' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='g';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'b' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='b';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'a' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='a';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'c' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='c';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'x' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='x';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'y' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='y';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'z' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='z';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'X' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_xmax;
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'Y' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_ymax;
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'Z' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_zmax;
		$$->value=0;
		$$->nodes=NULL;
	}
	| t_xmax { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_xmax;
		$$->value=0;
		$$->nodes=NULL;
	}
	| t_ymax { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_ymax;
		$$->value=0;
		$$->nodes=NULL;
	}
	| t_zmax { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_zmax;
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'i' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='i';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'u' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='u';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'v' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='v';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'd' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='d';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'm' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='m';
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'M' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_mmax;
		$$->value=0;
		$$->nodes=NULL;
	}
	| t_mmax { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_mmax;
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'R' {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=255;
		$$->nodes=NULL;
	}
	| 'G' {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=255;
		$$->nodes=NULL;
	}
	| 'B' {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=255;
		$$->nodes=NULL;
	}
	| 'A' {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=255;
		$$->nodes=NULL;
	}
	| 'I' {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=255;
		$$->nodes=NULL;
	}
	| 'C' {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=255;
		$$->nodes=NULL;
	}
	| t_rmax {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=255;
		$$->nodes=NULL;
	}
	| t_gmax {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=255;
		$$->nodes=NULL;
	}
	| t_bmax {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=255;
		$$->nodes=NULL;
	}
	| t_amax {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=255;
		$$->nodes=NULL;
	}
	| t_imax {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=255;
		$$->nodes=NULL;
	}
	| t_cmax {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=255;
		$$->nodes=NULL;
	}
 	| t_rmin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
 	| t_gmin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
 	| t_bmin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
 	| t_amin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
 	| t_imin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
 	| t_zmin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
 	| t_cmin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
	| 'D' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=1024;
		$$->nodes=NULL;
	}
	| t_dmax { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=1024;
		$$->nodes=NULL;
	}
	| t_dmin { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
	| t_mmin { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
 	| 'U' {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=56;
		$$->nodes=NULL;
	}
 	| t_umax {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=56;
		$$->nodes=NULL;
	}
 	| 'V' {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=78;
		$$->nodes=NULL;
	}
 	| t_vmax {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=78;
		$$->nodes=NULL;
	}
 	| t_umin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=-56;
		$$->nodes=NULL;
	}
 	| t_vmin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=-78;
		$$->nodes=NULL;
	}
 	| t_pmin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
 	| t_tmin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
 	| t_xmin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
 	| t_ymin {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
 	| t_pmax {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
 	| t_tmax {
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=v_int;
		$$->value=0;
		$$->nodes=NULL;
	}
        | exp '+' exp		{ 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='+';
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
        | exp '-' exp		{ 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='-';
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
        | exp '*' exp		{ 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='*';
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
        | exp '/' exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='/';
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	} 
        | exp '%' exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='%';
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	} 
        | exp '^' exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='^';
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	} 
        | exp '&' exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='&';
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	} 
        | exp '|' exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='|';
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	} 
        | '~' exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='~';
		$$->value=1;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$2;
	} 
        | '-' exp %prec t_sign	{ 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='-';
		$$->value=2;
		$$->nodes=malloc(2*sizeof(s_uf_tree *));
		$$->nodes[0]=malloc(sizeof(s_uf_tree) +2048);
		$$->nodes[0]->op_type=v_int;
		$$->nodes[0]->value=0;
		$$->nodes[0]->nodes=NULL;
		$$->nodes[1]=$2;
	}         
        | exp '?' exp ':' exp   { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='?';
		$$->value=3;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
		$$->nodes[2]=$5;
	}
	| exp t_and exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_and;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
	| exp t_or exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_or;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
	| exp t_eq exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_eq;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
	| exp t_neq exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_neq;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
	| exp t_le exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_le;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
	| exp t_be exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_be;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
	| exp '<' exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='<';
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
	| exp '>' exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='>';
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
	| '!' exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type='!';
		$$->value=1;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$2;
	}
	| exp t_shl exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_shl;
		$$->value=1;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
	| exp t_shr exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_shr;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
	| exp t_comma exp { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_comma;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$1;
		$$->nodes[1]=$3;
	}
	| t_src '(' exp ',' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_src;
		$$->value=3;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
		$$->nodes[2]=$7;
	}
	| t_rad '(' exp ',' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_rad;
		$$->value=3;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
		$$->nodes[2]=$7;
	}
	| t_cnv '(' exp ',' exp ',' exp ',' exp ',' exp ',' exp ',' exp ',' exp ',' exp ',' exp  ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_cnv;
		$$->value=10;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
		$$->nodes[2]=$7;
		$$->nodes[3]=$9;
		$$->nodes[4]=$11;
		$$->nodes[5]=$13;
		$$->nodes[6]=$15;
		$$->nodes[7]=$17;
		$$->nodes[8]=$19;
		$$->nodes[9]=$21;
	}
	| t_ctl '(' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_ctl;
		$$->value=1;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
	}
	| t_abs '(' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_abs;
		$$->value=1;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
	}
	| t_dif '(' exp ',' exp  ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_dif;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
	}
	| t_scl '(' exp ',' exp ','exp ',' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_scl;
		$$->value=5;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
		$$->nodes[2]=$7;
		$$->nodes[3]=$9;
		$$->nodes[4]=$11;
	}
	| t_val '(' exp ',' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_val;
		$$->value=3;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
		$$->nodes[2]=$7;
	}
	| t_add '(' exp ',' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_add;
		$$->value=3;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
		$$->nodes[2]=$7;
	}
	| t_sub '(' exp ',' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_sub;
		$$->value=3;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
		$$->nodes[2]=$7;
	}
 	| t_mix '(' exp ',' exp ',' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_mix;
		$$->value=4;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
		$$->nodes[2]=$7;
		$$->nodes[3]=$9;
	}
	| t_rnd '(' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_rnd;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
	}
	| t_rst '(' exp  ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_rst;
		$$->value=1;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
	}
	| t_c2d '(' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_c2d;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
	}
	| t_c2m '(' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_c2m;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
	}
	| t_r2x '(' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_r2x;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
	}
	| t_r2y '(' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_r2y;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
	}
	| t_min '(' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_min;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
	}
	| t_max '(' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_max;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
	}
	| t_put '(' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_put;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
	}
	| t_map '(' exp ',' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_map;
		$$->value=2;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
		$$->nodes[1]=$5;
	}
	| t_get '(' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_get;
		$$->value=1;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
	}
        | t_sin '(' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_sin;
		$$->value=1;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
	}            
        | t_cos '(' exp ')' { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_cos;
		$$->value=1;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
	}            
        | t_tan '(' exp ')'    { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_tan;
		$$->value=1;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
	}            
        | t_sqr '(' exp ')'    { 
		$$ = malloc(sizeof(s_uf_tree) +2048);
		$$->op_type=t_sqr;
		$$->value=1;
		$$->nodes=malloc(($$->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		$$->nodes[0]=$3;
	}
        | '(' exp ')' 		{ $$=$2; }
	| t_error { 
		$$=NULL; 
		YYABORT; 
	}
	;

%%

