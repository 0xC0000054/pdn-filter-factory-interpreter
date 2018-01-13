/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_UF_PARSER_H_INCLUDED
# define YY_YY_UF_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    t_comma = 258,
    t_abs = 259,
    t_add = 260,
    t_cnv = 261,
    t_ctl = 262,
    t_dif = 263,
    t_get = 264,
    t_put = 265,
    t_map = 266,
    t_max = 267,
    t_min = 268,
    t_mix = 269,
    t_rnd = 270,
    t_scl = 271,
    t_sqr = 272,
    t_src = 273,
    t_sub = 274,
    t_val = 275,
    t_c2d = 276,
    t_c2m = 277,
    t_cos = 278,
    t_r2x = 279,
    t_r2y = 280,
    t_rad = 281,
    t_rst = 282,
    t_sin = 283,
    t_tan = 284,
    t_and = 285,
    t_or = 286,
    t_eq = 287,
    t_neq = 288,
    t_shl = 289,
    t_shr = 290,
    t_le = 291,
    t_be = 292,
    t_sign = 293,
    t_rmin = 294,
    t_gmin = 295,
    t_bmin = 296,
    t_amin = 297,
    t_cmin = 298,
    t_imin = 299,
    t_umin = 300,
    t_vmin = 301,
    t_pmin = 302,
    t_tmin = 303,
    t_dmin = 304,
    t_mmin = 305,
    t_xmin = 306,
    t_ymin = 307,
    t_zmin = 308,
    t_rmax = 309,
    t_gmax = 310,
    t_bmax = 311,
    t_amax = 312,
    t_cmax = 313,
    t_imax = 314,
    t_umax = 315,
    t_vmax = 316,
    t_pmax = 317,
    t_tmax = 318,
    t_dmax = 319,
    t_mmax = 320,
    t_xmax = 321,
    t_ymax = 322,
    t_zmax = 323,
    v_int = 324,
    t_end_of_string = 325,
    t_error = 326
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_UF_PARSER_H_INCLUDED  */
