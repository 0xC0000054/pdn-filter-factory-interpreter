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
#ifndef _UF_PARSER_H
#define _UF_PARSER_H

typedef struct _uf_tree {
	int op_type;			/* symbol for operation */
	int value;			/* constant for v_int or number of nodes */
	struct _uf_tree **nodes;	/* nodes, if neccessary */
} s_uf_tree;

#define YYSTYPE s_uf_tree *

#ifdef YYDEBUG
extern int yydebug;
#endif

extern int depth;

s_uf_tree *get_uf_tree(char *s);
void free_tree(s_uf_tree *a);
void do_parse(char *s);
int yylex();
int yyparse();

#endif
