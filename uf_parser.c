/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "uf_parser.y" /* yacc.c:339  */

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
#include "uf_parser.h"

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

#line 122 "uf_parser.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "uf_parser.h".  */
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

/* Copy the second part of user declarations.  */

#line 245 "uf_parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
	  || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
	_Pragma ("GCC diagnostic push") \
	_Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
	_Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
	_Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
	  /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
	/* The OS might guarantee only one guard page at the bottom of the stack,
	   and a page size can be as small as 4096 bytes.  So we cannot safely
	   invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
	   to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
	   && ! ((defined YYMALLOC || defined malloc) \
			 && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
	 && (! defined __cplusplus \
		 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
	 ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
	  + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
	do                                                                  \
	  {                                                                 \
		YYSIZE_T yynewbytes;                                            \
		YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
		Stack = &yyptr->Stack_alloc;                                    \
		yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
		yyptr += yynewbytes / sizeof (*yyptr);                          \
	  }                                                                 \
	while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
	  __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
	  do                                        \
		{                                       \
		  YYSIZE_T yyi;                         \
		  for (yyi = 0; yyi < (Count); yyi++)   \
			(Dst)[yyi] = (Src)[yyi];            \
		}                                       \
	  while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  122
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2005

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  115
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  3
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  291

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
	   0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,    54,     2,     2,     2,    49,    32,     2,
	  51,    52,    47,    45,    50,    46,     2,    48,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     5,     2,
	  41,     2,    42,     4,     2,   110,   109,   112,    71,     2,
	   2,   108,     2,   111,     2,     2,     2,    73,     2,     2,
	   2,     2,   107,     2,     2,   113,   114,     2,    63,    64,
	  69,     2,     2,     2,    34,     2,     2,    59,    58,    60,
	  70,     2,     2,    57,     2,    65,     2,     2,     2,    72,
	   2,     2,     2,     2,    56,     2,     2,    66,    67,     2,
	  61,    62,    68,     2,    33,     2,    55,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	   2,     2,     2,     2,     2,     2,     1,     2,     3,     6,
	   7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
	  17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
	  27,    28,    29,    30,    31,    35,    36,    37,    38,    39,
	  40,    43,    44,    53,    74,    75,    76,    77,    78,    79,
	  80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
	  90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
	 100,   101,   102,   103,   104,   105,   106
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
	   0,   115,   115,   119,   132,   140,   141,   147,   153,   159,
	 165,   171,   177,   183,   189,   195,   201,   207,   213,   219,
	 225,   231,   237,   243,   249,   255,   261,   267,   273,   279,
	 285,   291,   297,   303,   309,   315,   321,   327,   333,   339,
	 345,   351,   357,   363,   369,   375,   381,   387,   393,   399,
	 405,   411,   417,   423,   429,   435,   441,   447,   453,   459,
	 465,   471,   477,   485,   493,   501,   509,   517,   525,   533,
	 541,   548,   559,   568,   576,   584,   592,   600,   608,   616,
	 624,   632,   639,   647,   655,   663,   672,   681,   697,   704,
	 711,   719,   730,   739,   748,   757,   767,   775,   782,   790,
	 798,   806,   814,   822,   830,   838,   846,   853,   860,   867,
	 874,   881,   882
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "t_comma", "'?'", "':'", "t_abs",
  "t_add", "t_cnv", "t_ctl", "t_dif", "t_get", "t_put", "t_map", "t_max",
  "t_min", "t_mix", "t_rnd", "t_scl", "t_sqr", "t_src", "t_sub", "t_val",
  "t_c2d", "t_c2m", "t_cos", "t_r2x", "t_r2y", "t_rad", "t_rst", "t_sin",
  "t_tan", "'&'", "'|'", "'^'", "t_and", "t_or", "t_eq", "t_neq", "t_shl",
  "t_shr", "'<'", "'>'", "t_le", "t_be", "'+'", "'-'", "'*'", "'/'", "'%'",
  "','", "'('", "')'", "t_sign", "'!'", "'~'", "'r'", "'g'", "'b'", "'a'",
  "'c'", "'x'", "'y'", "'X'", "'Y'", "'i'", "'u'", "'v'", "'z'", "'Z'",
  "'d'", "'D'", "'m'", "'M'", "t_rmin", "t_gmin", "t_bmin", "t_amin",
  "t_cmin", "t_imin", "t_umin", "t_vmin", "t_pmin", "t_tmin", "t_dmin",
  "t_mmin", "t_xmin", "t_ymin", "t_zmin", "t_rmax", "t_gmax", "t_bmax",
  "t_amax", "t_cmax", "t_imax", "t_umax", "t_vmax", "t_pmax", "t_tmax",
  "t_dmax", "t_mmax", "t_xmax", "t_ymax", "t_zmax", "v_int",
  "t_end_of_string", "t_error", "'R'", "'G'", "'B'", "'A'", "'I'", "'C'",
  "'U'", "'V'", "$accept", "input", "exp", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
	   0,   256,   257,   258,    63,    58,   259,   260,   261,   262,
	 263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
	 273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
	 283,   284,    38,   124,    94,   285,   286,   287,   288,   289,
	 290,    60,    62,   291,   292,    43,    45,    42,    47,    37,
	  44,    40,    41,   293,    33,   126,   114,   103,    98,    97,
	  99,   120,   121,    88,    89,   105,   117,   118,   122,    90,
	 100,    68,   109,    77,   294,   295,   296,   297,   298,   299,
	 300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
	 310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
	 320,   321,   322,   323,   324,   325,   326,    82,    71,    66,
	  65,    73,    67,    85,    86
};
# endif

#define YYPACT_NINF -42

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-42)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
	 STATE-NUM.  */
static const yytype_int16 yypact[] =
{
	 261,   -42,   -39,     9,    11,    12,    41,    42,    43,    65,
	  86,    89,    90,    91,    92,    93,    94,   117,   125,   131,
	 135,   136,   137,   153,   155,   156,   157,   160,   370,   370,
	 370,   370,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
	 -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
	 -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
	 -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
	 -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
	 -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
	  61,    10,   370,   370,   370,   370,   370,   370,   370,   370,
	 370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
	 370,   370,   370,   370,   370,   370,   370,   370,   -42,    87,
	 -42,   -42,   -42,   370,   370,   370,   370,   370,   370,   370,
	 370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
	 370,   370,   370,   -42,   114,  1067,  1093,   482,  1115,   503,
	1141,  1163,  1189,  1211,  1237,  1259,  1285,   529,  1307,  1333,
	1355,  1381,  1403,   550,  1429,  1451,  1477,   576,   597,   623,
	 -42,  1956,  1931,   -20,   -20,   -20,   -20,   154,   256,    -8,
	 363,   447,   -41,   -41,   -41,   -41,   -38,   -38,   -42,   -42,
	 -42,   -42,   370,   370,   -42,   370,   -42,   370,   370,   370,
	 370,   370,   370,   370,   -42,   370,   370,   370,   370,   370,
	 -42,   370,   370,   370,   -42,   -42,   -42,   370,  1499,  1525,
	 644,   670,   691,   717,   738,  1547,   764,  1573,  1595,  1621,
	1643,   785,   811,   832,   858,  1669,  1956,   370,   370,   -42,
	 -42,   -42,   -42,   -42,   370,   -42,   370,   370,   370,   370,
	 -42,   -42,   -42,   -42,   370,   879,  1691,  1717,  1739,   905,
	 926,   952,   973,   -42,   370,   370,   370,   -42,   -42,   -42,
	 -42,  1765,   999,  1787,   370,   -42,   370,  1813,  1020,   370,
	 -42,  1835,   370,  1861,   370,  1883,   370,  1909,   370,  1046,
	 -42
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
	 Performed when YYTABLE does not specify something else to do.  Zero
	 means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
	   0,     4,     0,     0,     0,     0,     0,     0,     0,     0,
	   0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	   0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	   0,     0,     6,     7,     8,     9,    10,    11,    12,    14,
	  15,    20,    21,    22,    13,    16,    23,    46,    24,    25,
	  39,    40,    41,    42,    45,    43,    54,    55,    56,    57,
	  48,    49,    58,    59,    44,    33,    34,    35,    36,    38,
	  37,    51,    53,    60,    61,    47,    26,    17,    18,    19,
	   5,   112,    27,    28,    29,    30,    31,    32,    50,    52,
	   0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	   0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	   0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
	  81,    70,     1,     0,     0,     0,     0,     0,     0,     0,
	   0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	   0,     0,     0,     3,     0,     0,     0,     0,     0,     0,
	   0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	   0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	 111,    84,     0,    68,    69,    67,    73,    74,    75,    76,
	  82,    83,    79,    80,    77,    78,    62,    63,    64,    65,
	  66,    89,     0,     0,    88,     0,   106,     0,     0,     0,
	   0,     0,     0,     0,   110,     0,     0,     0,     0,     0,
	 108,     0,     0,     0,    97,   107,   109,     0,     0,     0,
	   0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	   0,     0,     0,     0,     0,     0,    72,     0,     0,    90,
	 104,   105,   103,   102,     0,    96,     0,     0,     0,     0,
	  98,    99,   100,   101,     0,     0,     0,     0,     0,     0,
	   0,     0,     0,    93,     0,     0,     0,    85,    94,    92,
	  86,     0,     0,     0,     0,    95,     0,     0,     0,     0,
	  91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	  87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
	 -42,   -42,   -28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
	  -1,    90,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
	 positive, shift that token.  If negative, reduce the rule whose
	 number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
	 118,   119,   120,   121,   138,   139,   140,   141,   142,   140,
	 141,   142,    92,   123,   124,   128,   129,   130,   131,   132,
	 133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
	 131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
	 141,   142,   125,   126,   127,   128,   129,   130,   131,   132,
	 133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
	  93,   122,    94,    95,   144,   145,   146,   147,   148,   149,
	 150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
	 160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
	 123,   124,    96,    97,    98,   171,   172,   173,   174,   175,
	 176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
	 186,   187,   188,   189,   190,   143,    99,   123,   124,   125,
	 126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
	 136,   137,   138,   139,   140,   141,   142,   100,     0,   170,
	 101,   102,   103,   104,   105,   106,   125,   126,   127,   128,
	 129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
	 139,   140,   141,   142,   218,   219,   191,   220,   107,   221,
	 222,   223,   224,   225,   226,   227,   108,   228,   229,   230,
	 231,   232,   109,   233,   234,   235,   110,   111,   112,   236,
	 129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
	 139,   140,   141,   142,   113,     0,   114,   115,   116,   255,
	 256,   117,     0,     0,     0,     0,   257,     0,   258,   259,
	 260,   261,     0,     0,     0,     0,   262,     0,     0,     0,
	   0,     0,     0,     0,     0,     0,   271,   272,   273,     0,
	   0,     0,     0,     0,     0,     0,   277,     0,   278,     0,
	   0,   281,     0,     0,   283,     0,   285,     0,   287,     0,
	 289,    -2,     1,     0,     0,     0,     0,     2,     3,     4,
	   5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
	  15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
	  25,    26,    27,   130,   131,   132,   133,   134,   135,   136,
	 137,   138,   139,   140,   141,   142,     0,    28,     0,     0,
	   0,     0,    29,     0,     0,    30,    31,    32,    33,    34,
	  35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
	  45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
	  55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
	  65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
	  75,    76,    77,    78,    79,    80,     0,    81,    82,    83,
	  84,    85,    86,    87,    88,    89,     2,     3,     4,     5,
	   6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
	  16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
	  26,    27,   132,   133,   134,   135,   136,   137,   138,   139,
	 140,   141,   142,     0,     0,     0,    28,     0,     0,     0,
	   0,    29,     0,     0,    30,    31,    32,    33,    34,    35,
	  36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
	  46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
	  56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
	  66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
	  76,    77,    78,    79,    80,     0,    81,    82,    83,    84,
	  85,    86,    87,    88,    89,   123,   124,   133,   134,   135,
	 136,   137,   138,   139,   140,   141,   142,     0,     0,     0,
	   0,     0,     0,     0,     0,     0,   123,   124,     0,     0,
	   0,     0,     0,     0,   125,   126,   127,   128,   129,   130,
	 131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
	 141,   142,   123,   124,   194,   125,   126,   127,   128,   129,
	 130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
	 140,   141,   142,   123,   124,   196,     0,     0,     0,     0,
	   0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
	 134,   135,   136,   137,   138,   139,   140,   141,   142,   123,
	 124,   204,   125,   126,   127,   128,   129,   130,   131,   132,
	 133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
	 123,   124,   210,     0,     0,     0,     0,     0,   125,   126,
	 127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
	 137,   138,   139,   140,   141,   142,   123,   124,   214,   125,
	 126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
	 136,   137,   138,   139,   140,   141,   142,   123,   124,   215,
	   0,     0,     0,     0,     0,   125,   126,   127,   128,   129,
	 130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
	 140,   141,   142,   123,   124,   216,   125,   126,   127,   128,
	 129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
	 139,   140,   141,   142,   123,   124,   239,     0,     0,     0,
	   0,     0,   125,   126,   127,   128,   129,   130,   131,   132,
	 133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
	 123,   124,   240,   125,   126,   127,   128,   129,   130,   131,
	 132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
	 142,   123,   124,   241,     0,     0,     0,     0,     0,   125,
	 126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
	 136,   137,   138,   139,   140,   141,   142,   123,   124,   242,
	 125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
	 135,   136,   137,   138,   139,   140,   141,   142,   123,   124,
	 243,     0,     0,     0,     0,     0,   125,   126,   127,   128,
	 129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
	 139,   140,   141,   142,   123,   124,   245,   125,   126,   127,
	 128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
	 138,   139,   140,   141,   142,   123,   124,   250,     0,     0,
	   0,     0,     0,   125,   126,   127,   128,   129,   130,   131,
	 132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
	 142,   123,   124,   251,   125,   126,   127,   128,   129,   130,
	 131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
	 141,   142,   123,   124,   252,     0,     0,     0,     0,     0,
	 125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
	 135,   136,   137,   138,   139,   140,   141,   142,   123,   124,
	 253,   125,   126,   127,   128,   129,   130,   131,   132,   133,
	 134,   135,   136,   137,   138,   139,   140,   141,   142,   123,
	 124,   263,     0,     0,     0,     0,     0,   125,   126,   127,
	 128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
	 138,   139,   140,   141,   142,   123,   124,   267,   125,   126,
	 127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
	 137,   138,   139,   140,   141,   142,   123,   124,   268,     0,
	   0,     0,     0,     0,   125,   126,   127,   128,   129,   130,
	 131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
	 141,   142,   123,   124,   269,   125,   126,   127,   128,   129,
	 130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
	 140,   141,   142,   123,   124,   270,     0,     0,     0,     0,
	   0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
	 134,   135,   136,   137,   138,   139,   140,   141,   142,   123,
	 124,   275,   125,   126,   127,   128,   129,   130,   131,   132,
	 133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
	 123,   124,   280,     0,     0,     0,     0,     0,   125,   126,
	 127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
	 137,   138,   139,   140,   141,   142,   123,   124,   290,   125,
	 126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
	 136,   137,   138,   139,   140,   141,   142,   192,   123,   124,
	   0,     0,     0,     0,     0,   125,   126,   127,   128,   129,
	 130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
	 140,   141,   142,   193,   123,   124,     0,   125,   126,   127,
	 128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
	 138,   139,   140,   141,   142,   195,   123,   124,     0,     0,
	   0,     0,     0,   125,   126,   127,   128,   129,   130,   131,
	 132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
	 142,   197,   123,   124,     0,   125,   126,   127,   128,   129,
	 130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
	 140,   141,   142,   198,   123,   124,     0,     0,     0,     0,
	   0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
	 134,   135,   136,   137,   138,   139,   140,   141,   142,   199,
	 123,   124,     0,   125,   126,   127,   128,   129,   130,   131,
	 132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
	 142,   200,   123,   124,     0,     0,     0,     0,     0,   125,
	 126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
	 136,   137,   138,   139,   140,   141,   142,   201,   123,   124,
	   0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
	 134,   135,   136,   137,   138,   139,   140,   141,   142,   202,
	 123,   124,     0,     0,     0,     0,     0,   125,   126,   127,
	 128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
	 138,   139,   140,   141,   142,   203,   123,   124,     0,   125,
	 126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
	 136,   137,   138,   139,   140,   141,   142,   205,   123,   124,
	   0,     0,     0,     0,     0,   125,   126,   127,   128,   129,
	 130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
	 140,   141,   142,   206,   123,   124,     0,   125,   126,   127,
	 128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
	 138,   139,   140,   141,   142,   207,   123,   124,     0,     0,
	   0,     0,     0,   125,   126,   127,   128,   129,   130,   131,
	 132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
	 142,   208,   123,   124,     0,   125,   126,   127,   128,   129,
	 130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
	 140,   141,   142,   209,   123,   124,     0,     0,     0,     0,
	   0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
	 134,   135,   136,   137,   138,   139,   140,   141,   142,   211,
	 123,   124,     0,   125,   126,   127,   128,   129,   130,   131,
	 132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
	 142,   212,   123,   124,     0,     0,     0,     0,     0,   125,
	 126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
	 136,   137,   138,   139,   140,   141,   142,   213,   123,   124,
	   0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
	 134,   135,   136,   137,   138,   139,   140,   141,   142,   237,
	 123,   124,     0,     0,     0,     0,     0,   125,   126,   127,
	 128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
	 138,   139,   140,   141,   142,   238,   123,   124,     0,   125,
	 126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
	 136,   137,   138,   139,   140,   141,   142,   244,   123,   124,
	   0,     0,     0,     0,     0,   125,   126,   127,   128,   129,
	 130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
	 140,   141,   142,   246,   123,   124,     0,   125,   126,   127,
	 128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
	 138,   139,   140,   141,   142,   247,   123,   124,     0,     0,
	   0,     0,     0,   125,   126,   127,   128,   129,   130,   131,
	 132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
	 142,   248,   123,   124,     0,   125,   126,   127,   128,   129,
	 130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
	 140,   141,   142,   249,   123,   124,     0,     0,     0,     0,
	   0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
	 134,   135,   136,   137,   138,   139,   140,   141,   142,   254,
	 123,   124,     0,   125,   126,   127,   128,   129,   130,   131,
	 132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
	 142,   264,   123,   124,     0,     0,     0,     0,     0,   125,
	 126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
	 136,   137,   138,   139,   140,   141,   142,   265,   123,   124,
	   0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
	 134,   135,   136,   137,   138,   139,   140,   141,   142,   266,
	 123,   124,     0,     0,     0,     0,     0,   125,   126,   127,
	 128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
	 138,   139,   140,   141,   142,   274,   123,   124,     0,   125,
	 126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
	 136,   137,   138,   139,   140,   141,   142,   276,   123,   124,
	   0,     0,     0,     0,     0,   125,   126,   127,   128,   129,
	 130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
	 140,   141,   142,   279,   123,   124,     0,   125,   126,   127,
	 128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
	 138,   139,   140,   141,   142,   282,   123,   124,     0,     0,
	   0,     0,     0,   125,   126,   127,   128,   129,   130,   131,
	 132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
	 142,   284,   123,   124,     0,   125,   126,   127,   128,   129,
	 130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
	 140,   141,   142,   286,   123,   124,   217,     0,     0,     0,
	   0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
	 134,   135,   136,   137,   138,   139,   140,   141,   142,   288,
	 124,     0,     0,   125,   126,   127,   128,   129,   130,   131,
	 132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
	 142,     0,     0,     0,     0,     0,     0,     0,   125,   126,
	 127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
	 137,   138,   139,   140,   141,   142
};

static const yytype_int16 yycheck[] =
{
	  28,    29,    30,    31,    45,    46,    47,    48,    49,    47,
	  48,    49,    51,     3,     4,    35,    36,    37,    38,    39,
	  40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
	  38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
	  48,    49,    32,    33,    34,    35,    36,    37,    38,    39,
	  40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
	  51,     0,    51,    51,    92,    93,    94,    95,    96,    97,
	  98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
	 108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
	   3,     4,    51,    51,    51,   123,   124,   125,   126,   127,
	 128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
	 138,   139,   140,   141,   142,   105,    51,     3,     4,    32,
	  33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
	  43,    44,    45,    46,    47,    48,    49,    51,    -1,    52,
	  51,    51,    51,    51,    51,    51,    32,    33,    34,    35,
	  36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
	  46,    47,    48,    49,   192,   193,    52,   195,    51,   197,
	 198,   199,   200,   201,   202,   203,    51,   205,   206,   207,
	 208,   209,    51,   211,   212,   213,    51,    51,    51,   217,
	  36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
	  46,    47,    48,    49,    51,    -1,    51,    51,    51,   237,
	 238,    51,    -1,    -1,    -1,    -1,   244,    -1,   246,   247,
	 248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
	  -1,    -1,    -1,    -1,    -1,    -1,   264,   265,   266,    -1,
	  -1,    -1,    -1,    -1,    -1,    -1,   274,    -1,   276,    -1,
	  -1,   279,    -1,    -1,   282,    -1,   284,    -1,   286,    -1,
	 288,     0,     1,    -1,    -1,    -1,    -1,     6,     7,     8,
	   9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
	  19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
	  29,    30,    31,    37,    38,    39,    40,    41,    42,    43,
	  44,    45,    46,    47,    48,    49,    -1,    46,    -1,    -1,
	  -1,    -1,    51,    -1,    -1,    54,    55,    56,    57,    58,
	  59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
	  69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
	  79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
	  89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
	  99,   100,   101,   102,   103,   104,    -1,   106,   107,   108,
	 109,   110,   111,   112,   113,   114,     6,     7,     8,     9,
	  10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
	  20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
	  30,    31,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,    -1,    -1,    -1,    46,    -1,    -1,    -1,
	  -1,    51,    -1,    -1,    54,    55,    56,    57,    58,    59,
	  60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
	  70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
	  80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
	  90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
	 100,   101,   102,   103,   104,    -1,   106,   107,   108,   109,
	 110,   111,   112,   113,   114,     3,     4,    40,    41,    42,
	  43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
	  -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
	  -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
	  38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
	  48,    49,     3,     4,    52,    32,    33,    34,    35,    36,
	  37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,     3,     4,    52,    -1,    -1,    -1,    -1,
	  -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
	  41,    42,    43,    44,    45,    46,    47,    48,    49,     3,
	   4,    52,    32,    33,    34,    35,    36,    37,    38,    39,
	  40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
	   3,     4,    52,    -1,    -1,    -1,    -1,    -1,    32,    33,
	  34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
	  44,    45,    46,    47,    48,    49,     3,     4,    52,    32,
	  33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
	  43,    44,    45,    46,    47,    48,    49,     3,     4,    52,
	  -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
	  37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,     3,     4,    52,    32,    33,    34,    35,
	  36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
	  46,    47,    48,    49,     3,     4,    52,    -1,    -1,    -1,
	  -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
	  40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
	   3,     4,    52,    32,    33,    34,    35,    36,    37,    38,
	  39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
	  49,     3,     4,    52,    -1,    -1,    -1,    -1,    -1,    32,
	  33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
	  43,    44,    45,    46,    47,    48,    49,     3,     4,    52,
	  32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
	  42,    43,    44,    45,    46,    47,    48,    49,     3,     4,
	  52,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
	  36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
	  46,    47,    48,    49,     3,     4,    52,    32,    33,    34,
	  35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
	  45,    46,    47,    48,    49,     3,     4,    52,    -1,    -1,
	  -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
	  39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
	  49,     3,     4,    52,    32,    33,    34,    35,    36,    37,
	  38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
	  48,    49,     3,     4,    52,    -1,    -1,    -1,    -1,    -1,
	  32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
	  42,    43,    44,    45,    46,    47,    48,    49,     3,     4,
	  52,    32,    33,    34,    35,    36,    37,    38,    39,    40,
	  41,    42,    43,    44,    45,    46,    47,    48,    49,     3,
	   4,    52,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
	  35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
	  45,    46,    47,    48,    49,     3,     4,    52,    32,    33,
	  34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
	  44,    45,    46,    47,    48,    49,     3,     4,    52,    -1,
	  -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
	  38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
	  48,    49,     3,     4,    52,    32,    33,    34,    35,    36,
	  37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,     3,     4,    52,    -1,    -1,    -1,    -1,
	  -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
	  41,    42,    43,    44,    45,    46,    47,    48,    49,     3,
	   4,    52,    32,    33,    34,    35,    36,    37,    38,    39,
	  40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
	   3,     4,    52,    -1,    -1,    -1,    -1,    -1,    32,    33,
	  34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
	  44,    45,    46,    47,    48,    49,     3,     4,    52,    32,
	  33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
	  43,    44,    45,    46,    47,    48,    49,    50,     3,     4,
	  -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
	  37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,    50,     3,     4,    -1,    32,    33,    34,
	  35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
	  45,    46,    47,    48,    49,    50,     3,     4,    -1,    -1,
	  -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
	  39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
	  49,    50,     3,     4,    -1,    32,    33,    34,    35,    36,
	  37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,    50,     3,     4,    -1,    -1,    -1,    -1,
	  -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
	  41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
	   3,     4,    -1,    32,    33,    34,    35,    36,    37,    38,
	  39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
	  49,    50,     3,     4,    -1,    -1,    -1,    -1,    -1,    32,
	  33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
	  43,    44,    45,    46,    47,    48,    49,    50,     3,     4,
	  -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
	  41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
	   3,     4,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
	  35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
	  45,    46,    47,    48,    49,    50,     3,     4,    -1,    32,
	  33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
	  43,    44,    45,    46,    47,    48,    49,    50,     3,     4,
	  -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
	  37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,    50,     3,     4,    -1,    32,    33,    34,
	  35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
	  45,    46,    47,    48,    49,    50,     3,     4,    -1,    -1,
	  -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
	  39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
	  49,    50,     3,     4,    -1,    32,    33,    34,    35,    36,
	  37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,    50,     3,     4,    -1,    -1,    -1,    -1,
	  -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
	  41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
	   3,     4,    -1,    32,    33,    34,    35,    36,    37,    38,
	  39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
	  49,    50,     3,     4,    -1,    -1,    -1,    -1,    -1,    32,
	  33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
	  43,    44,    45,    46,    47,    48,    49,    50,     3,     4,
	  -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
	  41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
	   3,     4,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
	  35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
	  45,    46,    47,    48,    49,    50,     3,     4,    -1,    32,
	  33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
	  43,    44,    45,    46,    47,    48,    49,    50,     3,     4,
	  -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
	  37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,    50,     3,     4,    -1,    32,    33,    34,
	  35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
	  45,    46,    47,    48,    49,    50,     3,     4,    -1,    -1,
	  -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
	  39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
	  49,    50,     3,     4,    -1,    32,    33,    34,    35,    36,
	  37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,    50,     3,     4,    -1,    -1,    -1,    -1,
	  -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
	  41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
	   3,     4,    -1,    32,    33,    34,    35,    36,    37,    38,
	  39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
	  49,    50,     3,     4,    -1,    -1,    -1,    -1,    -1,    32,
	  33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
	  43,    44,    45,    46,    47,    48,    49,    50,     3,     4,
	  -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
	  41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
	   3,     4,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
	  35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
	  45,    46,    47,    48,    49,    50,     3,     4,    -1,    32,
	  33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
	  43,    44,    45,    46,    47,    48,    49,    50,     3,     4,
	  -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
	  37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,    50,     3,     4,    -1,    32,    33,    34,
	  35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
	  45,    46,    47,    48,    49,    50,     3,     4,    -1,    -1,
	  -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
	  39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
	  49,    50,     3,     4,    -1,    32,    33,    34,    35,    36,
	  37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,    50,     3,     4,     5,    -1,    -1,    -1,
	  -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
	  41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
	   4,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
	  39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
	  49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
	  34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
	  44,    45,    46,    47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
	 symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
	   0,     1,     6,     7,     8,     9,    10,    11,    12,    13,
	  14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
	  24,    25,    26,    27,    28,    29,    30,    31,    46,    51,
	  54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
	  64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
	  74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
	  84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
	  94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
	 104,   106,   107,   108,   109,   110,   111,   112,   113,   114,
	 116,   117,    51,    51,    51,    51,    51,    51,    51,    51,
	  51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
	  51,    51,    51,    51,    51,    51,    51,    51,   117,   117,
	 117,   117,     0,     3,     4,    32,    33,    34,    35,    36,
	  37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	  47,    48,    49,   105,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	  52,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,    52,    50,    50,    52,    50,    52,    50,    50,    50,
	  50,    50,    50,    50,    52,    50,    50,    50,    50,    50,
	  52,    50,    50,    50,    52,    52,    52,     5,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,    50,    50,    52,
	  52,    52,    52,    52,    50,    52,    50,    50,    50,    50,
	  52,    52,    52,    52,    50,   117,   117,   117,   117,   117,
	 117,   117,   117,    52,    50,    50,    50,    52,    52,    52,
	  52,   117,   117,   117,    50,    52,    50,   117,   117,    50,
	  52,   117,    50,   117,    50,   117,    50,   117,    50,   117,
	  52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
	   0,   115,   116,   116,   116,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
	 117,   117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
	   0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
	   1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
	   1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
	   1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
	   1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
	   1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
	   1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
	   2,     2,     5,     3,     3,     3,     3,     3,     3,     3,
	   3,     2,     3,     3,     3,     8,     8,    22,     4,     4,
	   6,    12,     8,     8,     8,    10,     6,     4,     6,     6,
	   6,     6,     6,     6,     6,     6,     4,     4,     4,     4,
	   4,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
	{                                                           \
	  yychar = (Token);                                         \
	  yylval = (Value);                                         \
	  YYPOPSTACK (yylen);                                       \
	  yystate = *yyssp;                                         \
	  goto yybackup;                                            \
	}                                                           \
  else                                                          \
	{                                                           \
	  yyerror (YY_("syntax error: cannot back up")); \
	  YYERROR;                                                  \
	}                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
	YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
	{                                                                     \
	  YYFPRINTF (stderr, "%s ", Title);                                   \
	  yy_symbol_print (stderr,                                            \
				  Type, Value); \
	  YYFPRINTF (stderr, "\n");                                           \
	}                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
	return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
	YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
			 yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
	{
	  int yybot = *yybottom;
	  YYFPRINTF (stderr, " %d", yybot);
	}
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
	yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
			 yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
	{
	  YYFPRINTF (stderr, "   $%d = ", yyi + 1);
	  yy_symbol_print (stderr,
					   yystos[yyssp[yyi + 1 - yynrhs]],
					   &(yyvsp[(yyi + 1) - (yynrhs)])
											  );
	  YYFPRINTF (stderr, "\n");
	}
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
	yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
	continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
	continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
	{
	  YYSIZE_T yyn = 0;
	  char const *yyp = yystr;

	  for (;;)
		switch (*++yyp)
		  {
		  case '\'':
		  case ',':
			goto do_not_strip_quotes;

		  case '\\':
			if (*++yyp != '\\')
			  goto do_not_strip_quotes;
			/* Fall through.  */
		  default:
			if (yyres)
			  yyres[yyn] = *yyp;
			yyn++;
			break;

		  case '"':
			if (yyres)
			  yyres[yyn] = '\0';
			return yyn;
		  }
	do_not_strip_quotes: ;
	}

  if (! yyres)
	return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
				yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
	 "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
	 - If this state is a consistent state with a default action, then
	   the only way this function was invoked is if the default action
	   is an error action.  In that case, don't check for expected
	   tokens because there are none.
	 - The only way there can be no lookahead present (in yychar) is if
	   this state is a consistent state with a default action.  Thus,
	   detecting the absence of a lookahead is sufficient to determine
	   that there is no unexpected or expected token to report.  In that
	   case, just report a simple "syntax error".
	 - Don't assume there isn't a lookahead just because this state is a
	   consistent state with a default action.  There might have been a
	   previous inconsistent state, consistent state with a non-default
	   action, or user semantic action that manipulated yychar.
	 - Of course, the expected token list depends on states to have
	   correct lookahead information, and it depends on the parser not
	   to perform extra reductions after fetching a lookahead from the
	   scanner and before detecting a syntax error.  Thus, state merging
	   (from LALR or IELR) and default reductions corrupt the expected
	   token list.  However, the list is correct for canonical LR with
	   one exception: it will still contain any token that will not be
	   accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
	{
	  int yyn = yypact[*yyssp];
	  yyarg[yycount++] = yytname[yytoken];
	  if (!yypact_value_is_default (yyn))
		{
		  /* Start YYX at -YYN if negative to avoid negative indexes in
			 YYCHECK.  In other words, skip the first -YYN actions for
			 this state because they are default actions.  */
		  int yyxbegin = yyn < 0 ? -yyn : 0;
		  /* Stay within bounds of both yycheck and yytname.  */
		  int yychecklim = YYLAST - yyn + 1;
		  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
		  int yyx;

		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
			if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
				&& !yytable_value_is_error (yytable[yyx + yyn]))
			  {
				if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
				  {
					yycount = 1;
					yysize = yysize0;
					break;
				  }
				yyarg[yycount++] = yytname[yyx];
				{
				  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
				  if (! (yysize <= yysize1
						 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
					return 2;
				  yysize = yysize1;
				}
			  }
		}
	}

  switch (yycount)
	{
# define YYCASE_(N, S)                      \
	  case N:                               \
		yyformat = S;                       \
	  break
	  YYCASE_(0, YY_("syntax error"));
	  YYCASE_(1, YY_("syntax error, unexpected %s"));
	  YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
	  YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
	  YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
	  YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
	}

  {
	YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
	if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
	  return 2;
	yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
	{
	  *yymsg_alloc = 2 * yysize;
	  if (! (yysize <= *yymsg_alloc
			 && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
		*yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
	  return 1;
	}

  /* Avoid sprintf, as that infringes on the user's name space.
	 Don't have undefined behavior even if the translation
	 produced a string with the wrong number of "%s"s.  */
  {
	char *yyp = *yymsg;
	int yyi = 0;
	while ((*yyp = *yyformat) != '\0')
	  if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyformat += 2;
		}
	  else
		{
		  yyp++;
		  yyformat++;
		}
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
	yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
	int yystate;
	/* Number of tokens to shift before error messages enabled.  */
	int yyerrstatus;

	/* The stacks and their tools:
	   'yyss': related to states.
	   'yyvs': related to semantic values.

	   Refer to the stacks through separate pointers, to allow yyoverflow
	   to reallocate them elsewhere.  */

	/* The state stack.  */
	yytype_int16 yyssa[YYINITDEPTH];
	yytype_int16 *yyss;
	yytype_int16 *yyssp;

	/* The semantic value stack.  */
	YYSTYPE yyvsa[YYINITDEPTH];
	YYSTYPE *yyvs;
	YYSTYPE *yyvsp;

	YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
	 action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
	 Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
	 have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
	{
	  /* Get the current used size of the three stacks, in elements.  */
	  YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
	  {
		/* Give user a chance to reallocate the stack.  Use copies of
		   these so that the &'s don't force the real ones into
		   memory.  */
		YYSTYPE *yyvs1 = yyvs;
		yytype_int16 *yyss1 = yyss;

		/* Each stack pointer address is followed by the size of the
		   data in use in that stack, in bytes.  This used to be a
		   conditional around just the two extra args, but that might
		   be undefined if yyoverflow is a macro.  */
		yyoverflow (YY_("memory exhausted"),
					&yyss1, yysize * sizeof (*yyssp),
					&yyvs1, yysize * sizeof (*yyvsp),
					&yystacksize);

		yyss = yyss1;
		yyvs = yyvs1;
	  }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
	  goto yyexhaustedlab;
# else
	  /* Extend the stack our own way.  */
	  if (YYMAXDEPTH <= yystacksize)
		goto yyexhaustedlab;
	  yystacksize *= 2;
	  if (YYMAXDEPTH < yystacksize)
		yystacksize = YYMAXDEPTH;

	  {
		yytype_int16 *yyss1 = yyss;
		union yyalloc *yyptr =
		  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
		if (! yyptr)
		  goto yyexhaustedlab;
		YYSTACK_RELOCATE (yyss_alloc, yyss);
		YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
		if (yyss1 != yyssa)
		  YYSTACK_FREE (yyss1);
	  }
# endif
#endif /* no yyoverflow */

	  yyssp = yyss + yysize - 1;
	  yyvsp = yyvs + yysize - 1;

	  YYDPRINTF ((stderr, "Stack size increased to %lu\n",
				  (unsigned long int) yystacksize));

	  if (yyss + yystacksize - 1 <= yyssp)
		YYABORT;
	}

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
	YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
	 lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
	goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
	{
	  YYDPRINTF ((stderr, "Reading a token: "));
	  yychar = yylex ();
	}

  if (yychar <= YYEOF)
	{
	  yychar = yytoken = YYEOF;
	  YYDPRINTF ((stderr, "Now at end of input.\n"));
	}
  else
	{
	  yytoken = YYTRANSLATE (yychar);
	  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
	}

  /* If the proper action on seeing token YYTOKEN is to reduce or to
	 detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
	goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
	{
	  if (yytable_value_is_error (yyn))
		goto yyerrlab;
	  yyn = -yyn;
	  goto yyreduce;
	}

  /* Count tokens shifted since error; after three, turn off error
	 status.  */
  if (yyerrstatus)
	yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
	goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
	 '$$ = $1'.

	 Otherwise, the following line sets YYVAL to garbage.
	 This behavior is undocumented and Bison
	 users should not rely upon it.  Assigning to YYVAL
	 unconditionally makes the parser a bit smaller, and it avoids a
	 GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
	{
		case 2:
#line 115 "uf_parser.y" /* yacc.c:1646  */
	{
		uf_root=NULL;
		YYABORT;
	}
#line 1845 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 3:
#line 119 "uf_parser.y" /* yacc.c:1646  */
	{
		if (depth==0) {
			uf_root=(yyvsp[-1]);
		} else {
			free_tree((yyvsp[-1]));
			if (depth<0)
				fprintf(stderr, "too many ')' !\n");
			else
				fprintf(stderr, "')' missing !\n");
			uf_root=NULL;
		}
		YYACCEPT;
	}
#line 1863 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 4:
#line 132 "uf_parser.y" /* yacc.c:1646  */
	{
		yyerrok;
		uf_root=NULL;
		YYABORT;
	}
#line 1873 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 5:
#line 140 "uf_parser.y" /* yacc.c:1646  */
	{ (yyval) = (yyvsp[0]); }
#line 1879 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 6:
#line 141 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='r';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 1890 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 7:
#line 147 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='g';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 1901 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 8:
#line 153 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='b';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 1912 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 9:
#line 159 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='a';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 1923 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 10:
#line 165 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='c';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 1934 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 11:
#line 171 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='x';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 1945 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 12:
#line 177 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='y';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 1956 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 13:
#line 183 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='z';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 1967 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 14:
#line 189 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_xmax;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 1978 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 15:
#line 195 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_ymax;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 1989 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 16:
#line 201 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_zmax;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2000 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 17:
#line 207 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_xmax;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2011 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 18:
#line 213 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_ymax;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2022 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 19:
#line 219 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_zmax;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2033 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 20:
#line 225 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='i';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2044 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 21:
#line 231 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='u';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2055 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 22:
#line 237 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='v';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2066 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 23:
#line 243 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='d';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2077 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 24:
#line 249 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='m';
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2088 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 25:
#line 255 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_mmax;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2099 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 26:
#line 261 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_mmax;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2110 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 27:
#line 267 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=255;
		(yyval)->nodes=NULL;
	}
#line 2121 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 28:
#line 273 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=255;
		(yyval)->nodes=NULL;
	}
#line 2132 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 29:
#line 279 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=255;
		(yyval)->nodes=NULL;
	}
#line 2143 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 30:
#line 285 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=255;
		(yyval)->nodes=NULL;
	}
#line 2154 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 31:
#line 291 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=255;
		(yyval)->nodes=NULL;
	}
#line 2165 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 32:
#line 297 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=255;
		(yyval)->nodes=NULL;
	}
#line 2176 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 33:
#line 303 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=255;
		(yyval)->nodes=NULL;
	}
#line 2187 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 34:
#line 309 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=255;
		(yyval)->nodes=NULL;
	}
#line 2198 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 35:
#line 315 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=255;
		(yyval)->nodes=NULL;
	}
#line 2209 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 36:
#line 321 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=255;
		(yyval)->nodes=NULL;
	}
#line 2220 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 37:
#line 327 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=255;
		(yyval)->nodes=NULL;
	}
#line 2231 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 38:
#line 333 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=255;
		(yyval)->nodes=NULL;
	}
#line 2242 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 39:
#line 339 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2253 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 40:
#line 345 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2264 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 41:
#line 351 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2275 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 42:
#line 357 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2286 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 43:
#line 363 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2297 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 44:
#line 369 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2308 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 45:
#line 375 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2319 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 46:
#line 381 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=1024;
		(yyval)->nodes=NULL;
	}
#line 2330 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 47:
#line 387 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=1024;
		(yyval)->nodes=NULL;
	}
#line 2341 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 48:
#line 393 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2352 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 49:
#line 399 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2363 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 50:
#line 405 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=56;
		(yyval)->nodes=NULL;
	}
#line 2374 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 51:
#line 411 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=56;
		(yyval)->nodes=NULL;
	}
#line 2385 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 52:
#line 417 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=78;
		(yyval)->nodes=NULL;
	}
#line 2396 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 53:
#line 423 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=78;
		(yyval)->nodes=NULL;
	}
#line 2407 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 54:
#line 429 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=-56;
		(yyval)->nodes=NULL;
	}
#line 2418 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 55:
#line 435 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=-78;
		(yyval)->nodes=NULL;
	}
#line 2429 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 56:
#line 441 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2440 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 57:
#line 447 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2451 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 58:
#line 453 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2462 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 59:
#line 459 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2473 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 60:
#line 465 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2484 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 61:
#line 471 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=v_int;
		(yyval)->value=0;
		(yyval)->nodes=NULL;
	}
#line 2495 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 62:
#line 477 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='+';
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2508 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 63:
#line 485 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='-';
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2521 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 64:
#line 493 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='*';
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2534 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 65:
#line 501 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='/';
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2547 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 66:
#line 509 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='%';
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2560 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 67:
#line 517 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='^';
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2573 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 68:
#line 525 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='&';
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2586 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 69:
#line 533 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='|';
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2599 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 70:
#line 541 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='~';
		(yyval)->value=1;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[0]);
	}
#line 2611 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 71:
#line 548 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='-';
		(yyval)->value=2;
		(yyval)->nodes=malloc(2*sizeof(s_uf_tree *));
		(yyval)->nodes[0]=malloc(sizeof(s_uf_tree) +2048);
		(yyval)->nodes[0]->op_type=v_int;
		(yyval)->nodes[0]->value=0;
		(yyval)->nodes[0]->nodes=NULL;
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2627 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 72:
#line 559 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='?';
		(yyval)->value=3;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-4]);
		(yyval)->nodes[1]=(yyvsp[-2]);
		(yyval)->nodes[2]=(yyvsp[0]);
	}
#line 2641 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 73:
#line 568 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_and;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2654 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 74:
#line 576 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_or;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2667 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 75:
#line 584 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_eq;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2680 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 76:
#line 592 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_neq;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2693 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 77:
#line 600 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_le;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2706 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 78:
#line 608 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_be;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2719 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 79:
#line 616 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='<';
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2732 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 80:
#line 624 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='>';
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2745 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 81:
#line 632 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type='!';
		(yyval)->value=1;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[0]);
	}
#line 2757 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 82:
#line 639 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_shl;
		(yyval)->value=1;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2770 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 83:
#line 647 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_shr;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2783 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 84:
#line 655 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_comma;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-2]);
		(yyval)->nodes[1]=(yyvsp[0]);
	}
#line 2796 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 85:
#line 663 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_src;
		(yyval)->value=3;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-5]);
		(yyval)->nodes[1]=(yyvsp[-3]);
		(yyval)->nodes[2]=(yyvsp[-1]);
	}
#line 2810 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 86:
#line 672 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_rad;
		(yyval)->value=3;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-5]);
		(yyval)->nodes[1]=(yyvsp[-3]);
		(yyval)->nodes[2]=(yyvsp[-1]);
	}
#line 2824 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 87:
#line 681 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_cnv;
		(yyval)->value=10;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-19]);
		(yyval)->nodes[1]=(yyvsp[-17]);
		(yyval)->nodes[2]=(yyvsp[-15]);
		(yyval)->nodes[3]=(yyvsp[-13]);
		(yyval)->nodes[4]=(yyvsp[-11]);
		(yyval)->nodes[5]=(yyvsp[-9]);
		(yyval)->nodes[6]=(yyvsp[-7]);
		(yyval)->nodes[7]=(yyvsp[-5]);
		(yyval)->nodes[8]=(yyvsp[-3]);
		(yyval)->nodes[9]=(yyvsp[-1]);
	}
#line 2845 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 88:
#line 697 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_ctl;
		(yyval)->value=1;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-1]);
	}
#line 2857 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 89:
#line 704 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_abs;
		(yyval)->value=1;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-1]);
	}
#line 2869 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 90:
#line 711 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_dif;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-3]);
		(yyval)->nodes[1]=(yyvsp[-1]);
	}
#line 2882 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 91:
#line 719 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_scl;
		(yyval)->value=5;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-9]);
		(yyval)->nodes[1]=(yyvsp[-7]);
		(yyval)->nodes[2]=(yyvsp[-5]);
		(yyval)->nodes[3]=(yyvsp[-3]);
		(yyval)->nodes[4]=(yyvsp[-1]);
	}
#line 2898 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 92:
#line 730 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_val;
		(yyval)->value=3;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-5]);
		(yyval)->nodes[1]=(yyvsp[-3]);
		(yyval)->nodes[2]=(yyvsp[-1]);
	}
#line 2912 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 93:
#line 739 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_add;
		(yyval)->value=3;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-5]);
		(yyval)->nodes[1]=(yyvsp[-3]);
		(yyval)->nodes[2]=(yyvsp[-1]);
	}
#line 2926 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 94:
#line 748 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_sub;
		(yyval)->value=3;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-5]);
		(yyval)->nodes[1]=(yyvsp[-3]);
		(yyval)->nodes[2]=(yyvsp[-1]);
	}
#line 2940 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 95:
#line 757 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_mix;
		(yyval)->value=4;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-7]);
		(yyval)->nodes[1]=(yyvsp[-5]);
		(yyval)->nodes[2]=(yyvsp[-3]);
		(yyval)->nodes[3]=(yyvsp[-1]);
	}
#line 2955 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 96:
#line 767 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_rnd;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-3]);
		(yyval)->nodes[1]=(yyvsp[-1]);
	}
#line 2968 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 97:
#line 775 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_rst;
		(yyval)->value=1;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-1]);
	}
#line 2980 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 98:
#line 782 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_c2d;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-3]);
		(yyval)->nodes[1]=(yyvsp[-1]);
	}
#line 2993 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 99:
#line 790 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_c2m;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-3]);
		(yyval)->nodes[1]=(yyvsp[-1]);
	}
#line 3006 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 100:
#line 798 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_r2x;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-3]);
		(yyval)->nodes[1]=(yyvsp[-1]);
	}
#line 3019 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 101:
#line 806 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_r2y;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-3]);
		(yyval)->nodes[1]=(yyvsp[-1]);
	}
#line 3032 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 102:
#line 814 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_min;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-3]);
		(yyval)->nodes[1]=(yyvsp[-1]);
	}
#line 3045 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 103:
#line 822 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_max;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-3]);
		(yyval)->nodes[1]=(yyvsp[-1]);
	}
#line 3058 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 104:
#line 830 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_put;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-3]);
		(yyval)->nodes[1]=(yyvsp[-1]);
	}
#line 3071 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 105:
#line 838 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_map;
		(yyval)->value=2;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-3]);
		(yyval)->nodes[1]=(yyvsp[-1]);
	}
#line 3084 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 106:
#line 846 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_get;
		(yyval)->value=1;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-1]);
	}
#line 3096 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 107:
#line 853 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_sin;
		(yyval)->value=1;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-1]);
	}
#line 3108 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 108:
#line 860 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_cos;
		(yyval)->value=1;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-1]);
	}
#line 3120 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 109:
#line 867 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_tan;
		(yyval)->value=1;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-1]);
	}
#line 3132 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 110:
#line 874 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval) = malloc(sizeof(s_uf_tree) +2048);
		(yyval)->op_type=t_sqr;
		(yyval)->value=1;
		(yyval)->nodes=malloc(((yyval)->value)*sizeof(s_uf_tree *) +4096); // pad the  buffer
		(yyval)->nodes[0]=(yyvsp[-1]);
	}
#line 3144 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 111:
#line 881 "uf_parser.y" /* yacc.c:1646  */
	{ (yyval)=(yyvsp[-1]); }
#line 3150 "uf_parser.c" /* yacc.c:1646  */
	break;

  case 112:
#line 882 "uf_parser.y" /* yacc.c:1646  */
	{
		(yyval)=NULL;
		YYABORT;
	}
#line 3159 "uf_parser.c" /* yacc.c:1646  */
	break;


#line 3163 "uf_parser.c" /* yacc.c:1646  */
	  default: break;
	}
  /* User semantic actions sometimes alter yychar, and that requires
	 that yytoken be updated with the new translation.  We take the
	 approach of translating immediately before every use of yytoken.
	 One alternative is translating here after every semantic action,
	 but that translation would be missed if the semantic action invokes
	 YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
	 if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
	 incorrect destructor might then be invoked immediately.  In the
	 case of YYERROR or YYBACKUP, subsequent parser actions might lead
	 to an incorrect destructor call or verbose syntax error message
	 before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
	 that goes to, based on the state we popped back to and the rule
	 number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
	yystate = yytable[yystate];
  else
	yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
	 user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
	{
	  ++yynerrs;
#if ! YYERROR_VERBOSE
	  yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
										yyssp, yytoken)
	  {
		char const *yymsgp = YY_("syntax error");
		int yysyntax_error_status;
		yysyntax_error_status = YYSYNTAX_ERROR;
		if (yysyntax_error_status == 0)
		  yymsgp = yymsg;
		else if (yysyntax_error_status == 1)
		  {
			if (yymsg != yymsgbuf)
			  YYSTACK_FREE (yymsg);
			yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
			if (!yymsg)
			  {
				yymsg = yymsgbuf;
				yymsg_alloc = sizeof yymsgbuf;
				yysyntax_error_status = 2;
			  }
			else
			  {
				yysyntax_error_status = YYSYNTAX_ERROR;
				yymsgp = yymsg;
			  }
		  }
		yyerror (yymsgp);
		if (yysyntax_error_status == 2)
		  goto yyexhaustedlab;
	  }
# undef YYSYNTAX_ERROR
#endif
	}



  if (yyerrstatus == 3)
	{
	  /* If just tried and failed to reuse lookahead token after an
		 error, discard it.  */

	  if (yychar <= YYEOF)
		{
		  /* Return failure if at end of input.  */
		  if (yychar == YYEOF)
			YYABORT;
		}
	  else
		{
		  yydestruct ("Error: discarding",
					  yytoken, &yylval);
		  yychar = YYEMPTY;
		}
	}

  /* Else will try to reuse lookahead token after shifting the error
	 token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
	 YYERROR and the label yyerrorlab therefore never appears in user
	 code.  */
  if (/*CONSTCOND*/ 0)
	 goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
	 this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
	{
	  yyn = yypact[yystate];
	  if (!yypact_value_is_default (yyn))
		{
		  yyn += YYTERROR;
		  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
			{
			  yyn = yytable[yyn];
			  if (0 < yyn)
				break;
			}
		}

	  /* Pop the current state because it cannot handle the error token.  */
	  if (yyssp == yyss)
		YYABORT;


	  yydestruct ("Error: popping",
				  yystos[yystate], yyvsp);
	  YYPOPSTACK (1);
	  yystate = *yyssp;
	  YY_STACK_PRINT (yyss, yyssp);
	}

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
	{
	  /* Make sure we have latest lookahead translation.  See comments at
		 user semantic actions for why this is necessary.  */
	  yytoken = YYTRANSLATE (yychar);
	  yydestruct ("Cleanup: discarding lookahead",
				  yytoken, &yylval);
	}
  /* Do not reclaim the symbols of the rule whose action triggered
	 this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
	{
	  yydestruct ("Cleanup: popping",
				  yystos[*yyssp], yyvsp);
	  YYPOPSTACK (1);
	}
#ifndef yyoverflow
  if (yyss != yyssa)
	YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
	YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 888 "uf_parser.y" /* yacc.c:1906  */


