/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_INT = 258,
     IF = 259,
     For = 260,
     T_FLOAT = 261,
     identifier = 262,
     Answer = 263,
     String = 264,
     Show = 265,
     Load = 266,
     Push = 267,
     Pop = 268,
     Top = 269,
     Size = 270,
     Char = 271,
     ShowHex = 272,
     T_PLUS = 273,
     T_MINUS = 274,
     T_MULTIPLY = 275,
     T_DIVIDE = 276,
     T_LEFT = 277,
     T_RIGHT = 278,
     IS = 279,
     INT = 280,
     FLOAT = 281,
     Str = 282,
     OPENLOOP = 283,
     ENDLOOP = 284,
     T_NEWLINE = 285,
     T_QUIT = 286,
     Single_Quotes = 287,
     Double_Quotes = 288,
     MoreThan = 289,
     MoreThan_EQUAL = 290,
     LessThan = 291,
     LessThan_EQUAL = 292,
     ELSE = 293,
     Not_EQUAL = 294,
     EQUAL = 295,
     NOT = 296,
     OR = 297,
     AND = 298,
     T_MOD = 299,
     T_RAISED = 300
   };
#endif
/* Tokens.  */
#define T_INT 258
#define IF 259
#define For 260
#define T_FLOAT 261
#define identifier 262
#define Answer 263
#define String 264
#define Show 265
#define Load 266
#define Push 267
#define Pop 268
#define Top 269
#define Size 270
#define Char 271
#define ShowHex 272
#define T_PLUS 273
#define T_MINUS 274
#define T_MULTIPLY 275
#define T_DIVIDE 276
#define T_LEFT 277
#define T_RIGHT 278
#define IS 279
#define INT 280
#define FLOAT 281
#define Str 282
#define OPENLOOP 283
#define ENDLOOP 284
#define T_NEWLINE 285
#define T_QUIT 286
#define Single_Quotes 287
#define Double_Quotes 288
#define MoreThan 289
#define MoreThan_EQUAL 290
#define LessThan 291
#define LessThan_EQUAL 292
#define ELSE 293
#define Not_EQUAL 294
#define EQUAL 295
#define NOT 296
#define OR 297
#define AND 298
#define T_MOD 299
#define T_RAISED 300




/* Copy the first part of user declarations.  */
#line 2 "calc.y"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
extern FILE* yyin;
FILE* fp;
struct node{
	char *data;
	struct node* next;
};
typedef struct node node;
node* getnode(char *data,node* next)
{
	node *p=(node*)malloc(sizeof(node));
	char *new_string = (char *)malloc(strlen(data) + 1); 
	strcpy(new_string,data);
	p->data=new_string;
	p->next=next;
return p;
}
void append(char *s,node* t)
{
	while(t->next != NULL)
	{
		t = t->next;
	}
	node *p=getnode(s,NULL);
	t->next = p;
	t = t -> next;
}
void newJump(int jump,node* t)
{
	while(t->next != NULL)
	{
		t = t->next;
	}
	char temp[100];
	sprintf(temp,".L%d",jump);
	node *p=getnode(temp,NULL);
	t->next = p;
	t = t -> next;
}
node *code;
node *data;
node *jump;
int answer = 0;
int countdata = 0;
int top =0;
int size =0;
int last_count_byte =0;
int num =0;
char a = '0';
bool checkJump = false;
int jumppoint = 1;
int count_byte = 0;
bool checkString = false;
int  reg[27] ; //เก็บค่า int ของตัวแปร
char regChar[27]; //เก็บค่า char ของตัวแปร
char *regString[27];//เก็บค่า string ของตัวแปร
float regFloat[100];
int regByte[27];
int type[100] ;//เก็บค่า type ของตัวแปร
bool checkBool = false;
bool checkRegEqual(char a,char b);
void yyerror(char* s);
int getAnswer();
int getRegValue(char c);
int LoadValue(char c,int number);
void LoadValueChar(char c,char assgin);
void LoadValueString(char c,char *s);
int LoadReg(char c1,char c2);
int showRegister(char c);
int LoadValueNum(char c,int number);
void ChangeString(char *s);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 81 "calc.y"
{
	char* s;
	int ival;
	float fval;
	char id;
}
/* Line 193 of yacc.c.  */
#line 272 "calc.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 285 "calc.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   387

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  220

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    18,    21,
      23,    26,    30,    35,    40,    42,    44,    48,    54,    60,
      64,    66,    70,    74,    78,    82,    86,    90,    94,    98,
     102,   106,   110,   114,   118,   122,   126,   130,   134,   138,
     142,   146,   148,   152,   156,   160,   164,   168,   172,   176,
     180,   184,   188,   192,   196,   198,   202,   206,   210,   214,
     218,   222,   225,   229,   233,   236,   238,   250,   272,   283,
     294,   305,   315,   330,   353,   365,   369,   373,   377,   381,
     385,   389,   393,   397,   401,   405,   409,   413,   417,   421,
     425,   429,   433
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    -1,    47,    48,    -1,    30,    -1,    10,
      49,    -1,    10,    51,    -1,    17,    51,    -1,    17,     7,
      -1,    31,    -1,    10,     7,    -1,     7,    24,     7,    -1,
      10,    33,     9,    33,    -1,    10,    32,    16,    32,    -1,
      52,    -1,    53,    -1,     7,    24,    51,    -1,     7,    24,
      32,    16,    32,    -1,     7,    24,    33,     9,    33,    -1,
       7,    24,    50,    -1,     6,    -1,    49,    18,    49,    -1,
      49,    19,    49,    -1,    49,    20,    49,    -1,    49,    21,
      49,    -1,    49,    45,    49,    -1,    49,    44,    49,    -1,
      22,    49,    23,    -1,    51,    45,    49,    -1,    51,    18,
      49,    -1,    51,    19,    49,    -1,    51,    20,    49,    -1,
      51,    21,    49,    -1,    51,    44,    49,    -1,    49,    18,
      51,    -1,    49,    19,    51,    -1,    49,    20,    51,    -1,
      49,    21,    51,    -1,    49,    45,    51,    -1,    49,    44,
      51,    -1,    51,    21,    51,    -1,     7,    -1,    50,    18,
      50,    -1,    50,    18,    51,    -1,    50,    19,    50,    -1,
      50,    19,    51,    -1,    50,    20,    50,    -1,    50,    20,
      51,    -1,    50,    21,    50,    -1,    50,    21,    51,    -1,
      50,    44,    50,    -1,    50,    44,    51,    -1,    50,    45,
      50,    -1,    22,    50,    23,    -1,     3,    -1,    51,    18,
      51,    -1,    51,    19,    51,    -1,    51,    20,    51,    -1,
      22,    51,    23,    -1,    51,    45,    51,    -1,    51,    44,
      51,    -1,    19,    51,    -1,    51,    43,    51,    -1,    51,
      42,    51,    -1,    41,    51,    -1,     4,    -1,     4,    54,
      30,    28,    30,    10,    33,     9,    33,    30,    29,    -1,
       4,    54,    30,    28,    30,    10,    33,     9,    33,    30,
      29,    38,    30,    28,    30,    10,    33,     9,    33,    30,
      29,    -1,     4,    54,    30,    28,    30,     7,    24,    51,
      30,    29,    -1,     4,    54,    30,    28,    30,     7,    24,
      16,    30,    29,    -1,     4,    54,    30,    28,    30,     7,
      24,     9,    30,    29,    -1,     4,    54,    30,    28,    30,
      10,     7,    30,    29,    -1,     5,     7,    36,    51,    51,
      30,    28,    30,    10,    33,     9,    33,    30,    29,    -1,
       5,     7,    36,    51,    51,    30,     5,     7,    36,    51,
      51,    30,    10,    33,     9,    33,    30,    10,    33,     9,
      33,    30,    -1,     5,     7,    36,    51,    51,    30,    28,
      30,    52,    30,    29,    -1,    51,    40,    51,    -1,    51,
      39,    51,    -1,    51,    34,    51,    -1,    51,    35,    51,
      -1,    51,    36,    51,    -1,     7,    40,    51,    -1,     7,
      39,    51,    -1,     7,    34,    51,    -1,     7,    35,    51,
      -1,     7,    36,    51,    -1,     7,    37,    51,    -1,     7,
      40,     7,    -1,     7,    39,     7,    -1,     7,    40,    16,
      -1,     7,    39,    16,    -1,     7,    40,     9,    -1,     7,
      39,     9,    -1,    50,    39,    51,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   111,   111,   112,   115,   116,   117,   132,   147,   165,
     166,   167,   168,   182,   189,   190,   191,   209,   227,   246,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   283,   284,   294,   307,   319,   330,   339,   352,   364,
     378,   389,   404,   415,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   433,   434,   450,   479,   480,
     481,   482,   485,   522,   601,   615,   616,   617,   618,   619,
     620,   628,   636,   644,   651,   658,   665,   678,   697,   698,
     699,   700,   701
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT", "IF", "For", "T_FLOAT",
  "identifier", "Answer", "String", "Show", "Load", "Push", "Pop", "Top",
  "Size", "Char", "ShowHex", "T_PLUS", "T_MINUS", "T_MULTIPLY", "T_DIVIDE",
  "T_LEFT", "T_RIGHT", "IS", "INT", "FLOAT", "Str", "OPENLOOP", "ENDLOOP",
  "T_NEWLINE", "T_QUIT", "Single_Quotes", "Double_Quotes", "MoreThan",
  "MoreThan_EQUAL", "LessThan", "LessThan_EQUAL", "ELSE", "Not_EQUAL",
  "EQUAL", "NOT", "OR", "AND", "T_MOD", "T_RAISED", "$accept",
  "calculation", "line", "mixed_expression", "assginValue", "expression",
  "Condition", "Loop", "Condition_stage", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     1,
       2,     3,     4,     4,     1,     1,     3,     5,     5,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     2,     1,    11,    21,    10,    10,
      10,     9,    14,    22,    11,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    65,     0,     0,     0,     0,     4,     9,
       3,    14,    15,    54,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    10,     0,     0,     0,     5,     6,
       8,     0,     7,     0,     0,     0,     0,     0,     0,    61,
      41,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,    19,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      87,    91,    89,    81,    86,    90,    88,    80,    53,    58,
      42,    43,    44,    45,    46,    47,    48,    49,    92,    50,
      51,     0,    52,    55,    56,    57,    77,    78,    79,    76,
      75,    63,    62,    60,    59,     0,     0,     0,     0,    27,
      13,    12,    21,    34,    22,    35,    23,    36,    24,    37,
      26,    39,    25,    38,    29,    55,    30,    56,    31,    57,
      32,    40,    33,    60,    28,    59,     0,     0,     0,    17,
      18,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,     0,     0,     0,     0,    70,    69,    68,     0,     0,
       0,     0,    66,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,    73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    10,    28,    41,    42,    11,    12,    20
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -36
static const yytype_int16 yypact[] =
{
     -36,   177,   -36,   149,    -2,   -13,    99,   150,   -36,   -36,
     -36,   -36,   -36,   -36,   347,    81,   156,    81,   269,   180,
     -15,   -20,     6,   -36,   -36,   170,    10,    28,   291,   214,
     -36,    81,   260,    81,    81,    81,    81,   108,   139,    63,
     -36,   297,   218,   319,   156,   156,   156,   156,    81,   156,
      -5,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    32,    81,   309,    50,    60,   313,   260,
     303,   208,    38,    71,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   260,   260,   260,   260,
     -36,   -36,   -36,   260,   -36,   -36,   -36,   260,   -36,   -36,
     325,   329,   325,   329,    64,   -35,    64,   -35,   260,    64,
     -35,    -5,    64,    63,    63,    65,   260,   260,   260,   260,
     260,   319,   319,    65,    65,    89,    94,    88,    92,   -36,
     -36,   -36,   331,   323,   331,   323,    84,    56,    84,    56,
      84,    56,    84,    56,   331,   335,   331,   335,    84,    98,
      84,    56,    84,    98,    84,    98,    13,    81,   224,   -36,
     -36,   102,    -6,   165,     1,   125,   103,   136,   143,   121,
     130,   134,   252,   138,   132,   147,    14,   141,   145,   159,
     -36,   163,    81,   168,   166,   -36,   -36,   -36,   173,    94,
     194,   175,   167,   256,   179,   -36,   176,   203,   187,   190,
     188,   201,   209,   231,   -36,   235,   213,   215,   217,   240,
     245,   232,   244,   234,   264,   254,   248,   -36,   255,   -36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,   -36,    11,    18,    -3,   115,   -36,   -36
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -62
static const yytype_int16 yytable[] =
{
      19,   166,    40,    29,    32,    21,   168,    59,    60,    13,
      62,    22,    39,    65,    43,    63,    64,   111,     3,    69,
     161,    18,    71,   162,   183,    15,    72,   167,    16,   169,
      86,    87,    88,    89,    93,    97,    70,    73,    66,    67,
      68,   101,   103,   105,   107,   108,   110,    17,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   100,   102,   104,   106,   127,   109,   112,   128,
     130,   133,   135,   137,   139,   141,   143,   145,   147,   149,
     151,   153,   155,    53,    13,   132,   134,   136,   138,   140,
     142,   144,   146,   148,   150,   152,   154,    13,    59,    60,
      15,    85,    13,    31,   131,    23,    24,    61,    62,    50,
      62,    13,    51,   157,    53,    90,    31,    91,    15,   156,
     159,    25,    17,   158,    92,   160,   165,    15,    13,    79,
      31,    26,    27,   173,   170,    17,    59,    60,    61,    62,
      17,   171,    13,    85,    15,   174,    94,    31,    95,    17,
     175,   176,    13,    13,   163,    96,    14,    30,    15,    13,
     177,    31,   172,    40,   178,   181,    17,   180,    15,    15,
     185,    16,    31,    13,   186,    15,    23,     2,    16,   189,
      17,     3,     4,   182,     5,    53,   193,     6,   187,    15,
      17,    17,    25,   188,     7,   -61,   191,    17,    51,    52,
      53,   190,   192,   194,   195,   196,   199,     8,     9,    61,
      62,    17,   198,   200,    54,    55,    56,   201,   202,    57,
      58,   203,    59,    60,    61,    62,    80,    81,    82,    83,
     204,    99,    80,    81,    82,    83,    51,    52,    53,   205,
     206,    99,    51,    52,    53,   207,   208,   210,   209,   211,
      59,    60,    84,    85,   164,   212,    59,    60,    84,    85,
      59,    60,    61,    62,   215,   213,    59,    60,    61,    62,
      51,    52,    53,   216,    51,    52,    53,   214,    51,    52,
      53,   218,   179,   217,     0,   219,   197,    44,    45,    46,
      47,   184,     0,     0,    59,    60,    61,    62,    59,    60,
      61,    62,    59,    60,    61,    62,     0,     0,    48,    74,
      75,    76,    77,    49,    50,    44,    45,    46,    47,     0,
      98,    74,    75,    76,    77,     0,   129,   -41,   -41,   -41,
     -41,    44,    45,    46,    47,    78,    79,    51,    52,    53,
       0,    49,    50,    82,    83,    46,    47,    78,    79,    53,
       0,    76,    77,   -41,   -41,    82,    83,    49,    50,     0,
       0,     0,     0,    61,    62,    59,    60,    84,    85,    49,
      50,    59,    60,    61,    62,    78,    79,     0,     0,    84,
      85,    33,    34,    35,    36,     0,    37,    38
};

static const yytype_int16 yycheck[] =
{
       3,     7,     7,     6,     7,     7,     5,    42,    43,     3,
      45,    24,    15,     7,    17,    30,    36,    22,     4,    22,
       7,     3,    25,    10,    10,    19,    16,    33,    22,    28,
      33,    34,    35,    36,    37,    38,    25,     9,    32,    33,
      22,    44,    45,    46,    47,    48,    49,    41,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      28,    64,    44,    45,    46,    47,    16,    49,    50,     9,
      32,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    20,     3,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     3,    42,    43,
      19,    45,     3,    22,    33,     6,     7,    44,    45,    45,
      45,     3,    18,    19,    20,     7,    22,     9,    19,    30,
      32,    22,    41,   126,    16,    33,    24,    19,     3,    45,
      22,    32,    33,    30,     9,    41,    42,    43,    44,    45,
      41,    16,     3,    45,    19,     9,     7,    22,     9,    41,
       7,    30,     3,     3,   157,    16,     7,     7,    19,     3,
      30,    22,   165,     7,    30,    33,    41,    29,    19,    19,
      29,    22,    22,     3,    29,    19,     6,     0,    22,   182,
      41,     4,     5,    36,     7,    20,   189,    10,    29,    19,
      41,    41,    22,    30,    17,    30,    30,    41,    18,    19,
      20,    33,    29,     9,    29,    38,    30,    30,    31,    44,
      45,    41,    33,    10,    34,    35,    36,    30,    28,    39,
      40,    33,    42,    43,    44,    45,    18,    19,    20,    21,
      29,    23,    18,    19,    20,    21,    18,    19,    20,    30,
       9,    23,    18,    19,    20,    10,    33,    30,    33,     9,
      42,    43,    44,    45,    30,    10,    42,    43,    44,    45,
      42,    43,    44,    45,    30,    33,    42,    43,    44,    45,
      18,    19,    20,     9,    18,    19,    20,    33,    18,    19,
      20,    33,    30,    29,    -1,    30,    30,    18,    19,    20,
      21,   176,    -1,    -1,    42,    43,    44,    45,    42,    43,
      44,    45,    42,    43,    44,    45,    -1,    -1,    39,    18,
      19,    20,    21,    44,    45,    18,    19,    20,    21,    -1,
      23,    18,    19,    20,    21,    -1,    23,    18,    19,    20,
      21,    18,    19,    20,    21,    44,    45,    18,    19,    20,
      -1,    44,    45,    20,    21,    20,    21,    44,    45,    20,
      -1,    20,    21,    44,    45,    20,    21,    44,    45,    -1,
      -1,    -1,    -1,    44,    45,    42,    43,    44,    45,    44,
      45,    42,    43,    44,    45,    44,    45,    -1,    -1,    44,
      45,    34,    35,    36,    37,    -1,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,     0,     4,     5,     7,    10,    17,    30,    31,
      48,    52,    53,     3,     7,    19,    22,    41,    50,    51,
      54,     7,    24,     6,     7,    22,    32,    33,    49,    51,
       7,    22,    51,    34,    35,    36,    37,    39,    40,    51,
       7,    50,    51,    51,    18,    19,    20,    21,    39,    44,
      45,    18,    19,    20,    34,    35,    36,    39,    40,    42,
      43,    44,    45,    30,    36,     7,    32,    33,    50,    51,
      49,    51,    16,     9,    18,    19,    20,    21,    44,    45,
      18,    19,    20,    21,    44,    45,    51,    51,    51,    51,
       7,     9,    16,    51,     7,     9,    16,    51,    23,    23,
      50,    51,    50,    51,    50,    51,    50,    51,    51,    50,
      51,    22,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    28,    51,    16,     9,    23,
      32,    33,    49,    51,    49,    51,    49,    51,    49,    51,
      49,    51,    49,    51,    49,    51,    49,    51,    49,    51,
      49,    51,    49,    51,    49,    51,    30,    19,    51,    32,
      33,     7,    10,    51,    30,    24,     7,    33,     5,    28,
       9,    16,    51,    30,     9,     7,    30,    30,    30,    30,
      29,    33,    36,    10,    52,    29,    29,    29,    30,    51,
      33,    30,    29,    51,     9,    29,    38,    30,    33,    30,
      10,    30,    28,    33,    29,    30,     9,    10,    33,    33,
      30,     9,    10,    33,    33,    30,     9,    29,    33,    30
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 116 "calc.y"
    { printf("%f\n", (yyvsp[(2) - (2)].fval));;}
    break;

  case 6:
#line 117 "calc.y"
    { printf("%i\n",(yyvsp[(2) - (2)].ival));  //แสดงค่า int
		
			char temp[100];
			sprintf(temp,".LC%d",countdata);
			append(temp,data);
			append("\t.string %d",data);
			sprintf(temp,"\tmov     esi, %d",(yyvsp[(2) - (2)].ival));
			append(temp,code);
			sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
			append(temp,code);
			append("\tcall    printf",code);
			countdata = countdata +1;

	
	;}
    break;

  case 7:
#line 132 "calc.y"
    { printf("%xh\n",(yyvsp[(2) - (2)].ival)); //แสดงค่า int เลขฐาน 16
	
	
			char temp[100];
			sprintf(temp,".LC%d",countdata);
			append(temp,data);
			append("\t.string %x",data);
			sprintf(temp,"\tmov     esi, %d",(yyvsp[(2) - (2)].ival));
			append(temp,code);
			sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
			append(temp,code);
			append("\tcall    printf",code);
			countdata = countdata +1;

	;}
    break;

  case 8:
#line 147 "calc.y"
    { if(type[(yyvsp[(2) - (2)].ival)] == 1){printf("%xh\n",reg[(yyvsp[(2) - (2)].ival)]);//แสดงค่า ตัวแปร int เลขฐาน 16
			char temp[100];
			sprintf(temp,".LC%d",countdata);
			append(temp,data);
			append("\t.string %x",data);
			sprintf(temp,"\tmov     eax, DWORD PTR [rbp-%d]",regByte[(yyvsp[(2) - (2)].ival)]);
			append(temp,code);
			append("\tmov     esi, eax",code);
			sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
			append(temp,code);
			append("\tmov     eax, 0",code);
			append("\tcall    printf",code);
			}
			else{
				printf("ERROR Type is not match");
			}

	;}
    break;

  case 9:
#line 165 "calc.y"
    { printf("bye!\n"); exit(0);;}
    break;

  case 10:
#line 166 "calc.y"
    { showRegister((yyvsp[(2) - (2)].ival));;}
    break;

  case 11:
#line 167 "calc.y"
    { LoadReg((yyvsp[(1) - (3)].ival),(yyvsp[(3) - (3)].ival));;}
    break;

  case 12:
#line 168 "calc.y"
    { ChangeString((yyvsp[(3) - (4)].s)); if(checkString == false){
			
				char temp[100];										//ปริ้นstring
				sprintf(temp,".LC%d",countdata);
				append(temp,data);
				sprintf(temp,"\t.string %s",(yyvsp[(3) - (4)].s));
				append(temp,data);
				sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
				append(temp,code);
				append("\tcall    printf",code);
				countdata = countdata +1;

		}
	;}
    break;

  case 13:
#line 182 "calc.y"
    { printf("%c\n",(yyvsp[(3) - (4)].id));
			char temp[100];											//ปริ้นChar
			sprintf(temp,"\tmov     edi,%d",(yyvsp[(3) - (4)].id));
			append(temp,code);
			append("\tcall    putchar",code);

	;}
    break;

  case 16:
#line 191 "calc.y"
    { type[(yyvsp[(1) - (3)].ival)] = 1;LoadValue((yyvsp[(1) - (3)].ival),(yyvsp[(3) - (3)].ival)); //ใส่ค่า int ให้กับตัวแปร 
			if(count_byte == 0) 
			{
				regByte[(yyvsp[(1) - (3)].ival)] = 4;
				char temp[100];
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], %d",regByte[(yyvsp[(1) - (3)].ival)],(yyvsp[(3) - (3)].ival));
				append(temp,code);
				count_byte = 4;
			}
			else
			{
				regByte[(yyvsp[(1) - (3)].ival)] = ((count_byte%4)+2)*4;
				char temp[100];
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], %d",regByte[(yyvsp[(1) - (3)].ival)],(yyvsp[(3) - (3)].ival));
				append(temp,code);
				count_byte = regByte[(yyvsp[(1) - (3)].ival)];
			}
	;}
    break;

  case 17:
#line 209 "calc.y"
    {type[(yyvsp[(1) - (5)].ival)] = 2;LoadValueChar((yyvsp[(1) - (5)].ival),(yyvsp[(4) - (5)].id)); //ใส่ค่า char ให้กับตัวแปร
			if(count_byte == 0)
			{
				regByte[(yyvsp[(1) - (5)].ival)] = 1;
				char temp[100];
				sprintf(temp,"\tmov     BYTE PTR [rbp-%d], %d",regByte[(yyvsp[(1) - (5)].ival)],(yyvsp[(4) - (5)].id));
				append(temp,code);
				count_byte = 1;
			}
			else
			{
				regByte[(yyvsp[(1) - (5)].ival)] = count_byte+1;
				char temp[100];
				sprintf(temp,"\tmov     BYTE PTR [rbp-%d], %d",regByte[(yyvsp[(1) - (5)].ival)],(yyvsp[(4) - (5)].id));
				append(temp,code);
				count_byte  = regByte[(yyvsp[(1) - (5)].ival)];
			}	
	;}
    break;

  case 18:
#line 227 "calc.y"
    {type[(yyvsp[(1) - (5)].ival)] = 3;char* s = (char*)malloc(200); s=(yyvsp[(4) - (5)].s);LoadValueString((yyvsp[(1) - (5)].ival),s); //ใส่ค่า string ให้กับตัวแปร
			if(count_byte == 0)
			{
				regByte[(yyvsp[(1) - (5)].ival)] = 8;
				char temp[100];
				sprintf(temp,"\tmov     BYTE PTR [rbp-%d], %d",regByte[(yyvsp[(1) - (5)].ival)],(yyvsp[(4) - (5)].s));
				append(temp,code);
				count_byte = 1;
			}
			else
			{
				regByte[(yyvsp[(1) - (5)].ival)] = (abs(count_byte-8)+1)*8;
				char temp[100];
				sprintf(temp,"\tmov     BYTE PTR [rbp-%d], %d",regByte[(yyvsp[(1) - (5)].ival)],(yyvsp[(4) - (5)].s));
				append(temp,code);
				count_byte  = regByte[(yyvsp[(1) - (5)].ival)];
			}	
	;}
    break;

  case 19:
#line 247 "calc.y"
    { 	
			type[(yyvsp[(1) - (3)].ival)] = 1;
			regByte[(yyvsp[(1) - (3)].ival)] = num;
			reg[(yyvsp[(1) - (3)].ival)] = (yyvsp[(3) - (3)].ival);

		;}
    break;

  case 20:
#line 257 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (1)].fval); ;}
    break;

  case 21:
#line 258 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].fval) + (yyvsp[(3) - (3)].fval); ;}
    break;

  case 22:
#line 259 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].fval) - (yyvsp[(3) - (3)].fval); ;}
    break;

  case 23:
#line 260 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].fval) * (yyvsp[(3) - (3)].fval); ;}
    break;

  case 24:
#line 261 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].fval) / (yyvsp[(3) - (3)].fval); ;}
    break;

  case 25:
#line 262 "calc.y"
    { (yyval.fval) = pow ((yyvsp[(1) - (3)].fval), (yyvsp[(3) - (3)].fval));;}
    break;

  case 26:
#line 263 "calc.y"
    { (yyval.fval) = fmod((yyvsp[(1) - (3)].fval),(yyvsp[(3) - (3)].fval));;}
    break;

  case 27:
#line 264 "calc.y"
    { (yyval.fval) = (yyvsp[(2) - (3)].fval); ;}
    break;

  case 28:
#line 265 "calc.y"
    { (yyval.fval) = pow ((yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].fval));;}
    break;

  case 29:
#line 266 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].fval); ;}
    break;

  case 30:
#line 267 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].ival) - (yyvsp[(3) - (3)].fval); ;}
    break;

  case 31:
#line 268 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].fval); ;}
    break;

  case 32:
#line 269 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].ival) / (yyvsp[(3) - (3)].fval); ;}
    break;

  case 33:
#line 270 "calc.y"
    { (yyval.fval) = fmod((yyvsp[(1) - (3)].ival),(yyvsp[(3) - (3)].fval));;}
    break;

  case 34:
#line 271 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].fval) + (yyvsp[(3) - (3)].ival); ;}
    break;

  case 35:
#line 272 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].fval) - (yyvsp[(3) - (3)].ival); ;}
    break;

  case 36:
#line 273 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].fval) * (yyvsp[(3) - (3)].ival); ;}
    break;

  case 37:
#line 274 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].fval) / (yyvsp[(3) - (3)].ival); ;}
    break;

  case 38:
#line 275 "calc.y"
    { (yyval.fval) = pow ((yyvsp[(1) - (3)].fval), (yyvsp[(3) - (3)].ival));;}
    break;

  case 39:
#line 276 "calc.y"
    { (yyval.fval) = fmod((yyvsp[(1) - (3)].fval),(yyvsp[(3) - (3)].ival));;}
    break;

  case 40:
#line 277 "calc.y"
    { (yyval.fval) = (yyvsp[(1) - (3)].ival) / (float)(yyvsp[(3) - (3)].ival); ;}
    break;

  case 41:
#line 283 "calc.y"
    { if(type[(yyvsp[(1) - (1)].ival)] == 1){(yyval.ival) = getRegValue((yyvsp[(1) - (1)].ival));last_count_byte = regByte[(yyvsp[(1) - (1)].ival)];}else{printf("ERROR Not math type\n");} ;}
    break;

  case 42:
#line 284 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].ival);
	  			 num = ((count_byte%4)+2)*4;
				char temp[100];
				append("\tmov     eax, DWORD PTR [rbp]",code);
				append("\tmov     edx, DWORD PTR [rbp]",code);
				append("\tlea     eax, [rdx+rax]",code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d]",num);
				append(temp,code);
				count_byte = num;
	  ;}
    break;

  case 43:
#line 294 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].ival);
				
				 num = ((count_byte%4)+2)*4;
				char temp[100];
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d]",last_count_byte);
				append(temp,code);
				sprintf(temp,"\tadd     eax,%d",(yyvsp[(3) - (3)].ival));
				append(temp,code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",num);
				append(temp,code);
				count_byte = num;
	  
	  ;}
    break;

  case 44:
#line 307 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) - (yyvsp[(3) - (3)].ival);
	  			num = ((count_byte%4)+2)*4;
				char temp[100];
	  			append("\tmov     eax, DWORD PTR [rbp]",code);
				append("\tmov     edx, DWORD PTR [rbp]",code);
				append("\tmov     ecx, edx",code);
				append("\tsub     ecx, eax",code);
				append("\tmov     eax, ecx",code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",num);
				append(temp,code);
				count_byte = num;
	  ;}
    break;

  case 45:
#line 319 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival)-(yyvsp[(3) - (3)].ival);
	  			num = ((count_byte%4)+2)*4;
				char temp[100];
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d]",last_count_byte);
				append(temp,code);
				sprintf(temp,"\tsub     eax,%d",(yyvsp[(3) - (3)].ival));
				append(temp,code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",num);
				append(temp,code);
				count_byte = num;
	  ;}
    break;

  case 46:
#line 330 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].ival);
	  			num = ((count_byte%4)+2)*4;
				char temp[100];
				append("\tmov     eax, DWORD PTR [rbp]",code);
				append("\timul    eax, DWORD PTR [rbp]",code);								
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d],eax",num);
				append(temp,code);
				count_byte = num;
	  ;}
    break;

  case 47:
#line 339 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].ival);
	  			num = ((count_byte%4)+2)*4;
				char temp[100];
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d]",last_count_byte);
				append(temp,code);
				append("\tmov     eax, edx",code);
				append("\tsal     eax, 2",code);
				append("\tadd     eax, edx",code);
				append("\tadd     eax, eax",code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",num);
				append(temp,code);
				count_byte = num;
	  ;}
    break;

  case 48:
#line 352 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) / (yyvsp[(3) - (3)].ival);
	  			num = ((count_byte%4)+2)*4;
				char temp[100];
				append("\tmov     eax, DWORD PTR [rbp]",code);
				append("\tmov     edx, eax",code);
				append("\t sar     edx, 31",code);
				append("\tidiv    eax, DWORD PTR [rbp]",code);								
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d],eax",num);
				append(temp,code);
				count_byte = num;
	  
	  ;}
    break;

  case 49:
#line 364 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival)/(yyvsp[(3) - (3)].ival);
	  			num = ((count_byte%4)+2)*4;
				char temp[100];
				sprintf(temp,"\tmov     eax,DWORD PTR [rbp-%d]",last_count_byte);
				append(temp,code);
				append("\tmov     edx, eax",code);
				append("\tshr     edx, 31",code);
				append("\tlea      eax, [rdx+rax]",code);
				append("\tsar      eax",code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",num);
				append(temp,code);
				count_byte = num;
	  
	  ;}
    break;

  case 50:
#line 378 "calc.y"
    { (yyval.ival) = fmod((yyvsp[(1) - (3)].ival) ,(yyvsp[(3) - (3)].ival));
				num = ((count_byte%4)+2)*4;
				char temp[100];
				append("\tmov     eax, DWORD PTR [rbp]",code);
				append("\tmov     edx, eax",code);
				append("\t sar     edx, 31",code);
				append("\tidiv    eax, DWORD PTR [rbp]",code);								
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d],eax",num);
				append(temp,code);
				count_byte = num;
	  ;}
    break;

  case 51:
#line 389 "calc.y"
    { (yyval.ival) = fmod((yyvsp[(1) - (3)].ival) ,(yyvsp[(3) - (3)].ival));
				num = ((count_byte%4)+2)*4;
				char temp[100];
				sprintf(temp,"\tmov     eax,DWORD PTR [rbp-%d]",last_count_byte);
				append(temp,code);
				append("\tmov     edx, eax",code);
				append("\tsar     edx, 31",code);
				append("\tshr     edx, 31",code);
				append("\tadd     eax, edx",code);
				append("\tand     eax, 1",code);
				append("\tsub     eax, edx",code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",num);
				append(temp,code);
				count_byte = num;
	  ;}
    break;

  case 52:
#line 404 "calc.y"
    { (yyval.ival) = pow((yyvsp[(1) - (3)].ival) ,(yyvsp[(3) - (3)].ival));

	  			num = ((count_byte%4)+2)*4;
				char temp[100];
				append("\tmov     eax, DWORD PTR [rbp]",code);
				append("\tmov     edx, DWORD PTR [rbp]",code);
				append("\txor     eax, edx",code);								
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d],eax",num);
				append(temp,code);
				count_byte = num;
	  ;}
    break;

  case 53:
#line 415 "calc.y"
    { (yyval.ival) = (yyvsp[(2) - (3)].ival); ;}
    break;

  case 54:
#line 420 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 55:
#line 421 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].ival); ;}
    break;

  case 56:
#line 422 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) - (yyvsp[(3) - (3)].ival); ;}
    break;

  case 57:
#line 423 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].ival); ;}
    break;

  case 58:
#line 424 "calc.y"
    { (yyval.ival) = (yyvsp[(2) - (3)].ival); ;}
    break;

  case 59:
#line 425 "calc.y"
    { (yyval.ival) = pow ((yyvsp[(1) - (3)].ival), (yyvsp[(3) - (3)].ival)); ;}
    break;

  case 60:
#line 426 "calc.y"
    { (yyval.ival) = fmod((yyvsp[(1) - (3)].ival),(yyvsp[(3) - (3)].ival));;}
    break;

  case 61:
#line 427 "calc.y"
    { (yyval.ival) = -(yyvsp[(2) - (2)].ival);;}
    break;

  case 62:
#line 428 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) && (yyvsp[(3) - (3)].ival);;}
    break;

  case 63:
#line 429 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) || (yyvsp[(3) - (3)].ival);;}
    break;

  case 64:
#line 430 "calc.y"
    { (yyval.ival) = !(yyvsp[(2) - (2)].ival);;}
    break;

  case 65:
#line 433 "calc.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival);;}
    break;

  case 66:
#line 435 "calc.y"
    {if(checkBool){ printf("%s\n",(yyvsp[(8) - (11)].s)); }
		  	
				char temp[100];
				sprintf(temp,".LC%d",countdata);
				append(temp,data);
				sprintf(temp,"\t.string %s",(yyvsp[(8) - (11)].s));
				append(temp,data);
				sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
				append(temp,code);
				append("\tcall    printf",code);
				jumppoint = jumppoint +1;
				sprintf(temp,".L%d:",jumppoint);
				append(temp,code);
				countdata = countdata +1;
		  ;}
    break;

  case 67:
#line 451 "calc.y"
    {if(checkBool){ printf("%s\n",(yyvsp[(8) - (21)].s));}
		  	
				char temp[100];
				sprintf(temp,".LC%d",countdata);
				append(temp,data);
				sprintf(temp,"\t.string %s",(yyvsp[(8) - (21)].s));
				append(temp,data);
				sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
				append(temp,code);
				append("\tcall    printf",code);
				jumppoint = jumppoint+2;
				sprintf(temp,"\tjmp     .L%d",jumppoint);
				append(temp,code);
				countdata = countdata +1;
				sprintf(temp,".LC%d",countdata);
				append(temp,data);
				sprintf(temp,"\t.string %s",(yyvsp[(18) - (21)].s));
				append(temp,data);
				sprintf(temp,".L%d",jumppoint-1);
				append(temp,code);
				sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
				append(temp,code);
				append("\tmov     eax, 0",code);
				append("\tcall    printf",code);
				newJump(jumppoint,code);
				countdata = countdata +1;

		  ;}
    break;

  case 68:
#line 479 "calc.y"
    {if(checkBool){type[(yyvsp[(6) - (10)].ival)] = 1;LoadValue((yyvsp[(6) - (10)].ival),(yyvsp[(8) - (10)].ival));};}
    break;

  case 69:
#line 480 "calc.y"
    {if(checkBool){type[(yyvsp[(6) - (10)].ival)] = 2;LoadValueChar((yyvsp[(6) - (10)].ival),(yyvsp[(8) - (10)].id));};}
    break;

  case 70:
#line 481 "calc.y"
    {if(checkBool){type[(yyvsp[(6) - (10)].ival)] = 3;char* s = (char*)malloc(100); s=(yyvsp[(8) - (10)].s);  LoadValueString((yyvsp[(6) - (10)].ival),s);};}
    break;

  case 71:
#line 482 "calc.y"
    {if(checkBool){printf("%d\n",reg[(yyvsp[(7) - (9)].ival)]);};}
    break;

  case 72:
#line 485 "calc.y"
    {int start = reg[(yyvsp[(2) - (14)].ival)];if(type[(yyvsp[(2) - (14)].ival)]==1){for(start;start<(yyvsp[(4) - (14)].ival);start=start+(yyvsp[(5) - (14)].ival)){printf("%s\n",(yyvsp[(11) - (14)].s));}
										//Loopเดียว
				char temp[100];
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(2) - (14)].ival)],reg[(yyvsp[(2) - (14)].ival)]);
				append(temp,code);
				sprintf(temp,"\tjmp     .L%d",jumppoint+1);
				append(temp,code);
				sprintf(temp,".L%d:",jumppoint+2);
				append(temp,code);
				sprintf(temp,".LC%d",countdata);
				append(temp,data);
				sprintf(temp,"\t.string %s",(yyvsp[(11) - (14)].s));
				append(temp,data);
				sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
				append(temp,code);
				append("\tcall    printf",code);
				countdata = countdata +1;
				sprintf(temp,"\tadd     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(2) - (14)].ival)],(yyvsp[(5) - (14)].ival));
				append(temp,code);
				sprintf(temp,".L%d:",jumppoint+1);
				append(temp,code);
				sprintf(temp,"cmp     DWORD PTR [rbp-%d], %d",regByte[(yyvsp[(2) - (14)].ival)],(yyvsp[(4) - (14)].ival)-1);
				append(temp,code);
				append("\tsetle   al",code);
				append("\ttest    al, al",code);
				sprintf(temp,"\tjne     .L%d",jumppoint+2);
				append(temp,code);
				jumppoint = jumppoint +3;
				newJump(jumppoint,code);
				count_byte = ((count_byte%4)+2)*4;				
				}
				else{
					printf("ERROR Type is not match in Int \n");
				}


	;}
    break;

  case 73:
#line 523 "calc.y"
    {	if( ( type[(yyvsp[(2) - (22)].ival)] == 1) && (type[(yyvsp[(8) - (22)].ival)] == 1) ){ //Loop ซ้อน Loop
				int start = reg[(yyvsp[(2) - (22)].ival)];
				int start2 = reg[(yyvsp[(8) - (22)].ival)];
				for(start;start<(yyvsp[(4) - (22)].ival);start=start+(yyvsp[(5) - (22)].ival))
				{
					
						for(start2;start2<(yyvsp[(10) - (22)].ival);start2=start2+(yyvsp[(11) - (22)].ival))
						{
							printf("%s\n",(yyvsp[(15) - (22)].s));
						}
						start2 =0;

						printf("%s\n",(yyvsp[(20) - (22)].s));
				}
				char temp[100];
									sprintf(temp,"\tmov     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(2) - (22)].ival)],reg[(yyvsp[(2) - (22)].ival)]);
									append(temp,code);
									sprintf(temp,"\tjmp     .L%d",jumppoint+1);
									append(temp,code);
									sprintf(temp,".L%d:",jumppoint+4);
									append(temp,code);
									sprintf(temp,".LBB%d:",jumppoint+4);
									append(temp,code);
									sprintf(temp,"\tmov     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(8) - (22)].ival)],reg[(yyvsp[(8) - (22)].ival)]);
									append(temp,code);
									sprintf(temp,"\tjmp     .L%d",jumppoint+2);
									append(temp,code);
									sprintf(temp,".L%d:",jumppoint+3);
									append(temp,code);
									sprintf(temp,".LC%d",countdata);
									append(temp,data);
									sprintf(temp,"\t.string %s",(yyvsp[(20) - (22)].s));
									append(temp,data);
									sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
									append(temp,code);
									append("mov     eax, 0",code);
									append("\tcall    printf",code);
									countdata = countdata +1;
									sprintf(temp,"\tadd     DWORD PTR [rbp-%d], %d",regByte[(yyvsp[(8) - (22)].ival)],(yyvsp[(11) - (22)].ival));
									append(temp,code);
									sprintf(temp,".L%d:",jumppoint+2);
									append(temp,code);
									sprintf(temp,"\tcmp     DWORD PTR [rbp-%d], %d",regByte[(yyvsp[(8) - (22)].ival)],(yyvsp[(10) - (22)].ival)-1);
									append(temp,code);
									append("\tsetle   al",code);
									append("\ttest    al, al",code);
									sprintf(temp,"\tjne     .L%d",jumppoint+3);
									append(temp,code);
									sprintf(temp,".LBB%d:",jumppoint+4);
									append(temp,code);
									sprintf(temp,".LC%d",countdata);
									append(temp,data);
									sprintf(temp,"\t.string %s",(yyvsp[(15) - (22)].s));
									append(temp,data);
									sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
									append(temp,code);
									append("\tmov     eax, 0",code);
									append("\tcall    printf",code);
									countdata = countdata +1;
									sprintf(temp,".LBE%d:",jumppoint+3);
									append(temp,code);
									sprintf(temp,"\tadd     DWORD PTR [rbp-%d], %d",regByte[(yyvsp[(2) - (22)].ival)],(yyvsp[(5) - (22)].ival));
									append(temp,code);
									sprintf(temp,".L%d:",jumppoint+1);
									append(temp,code);
									sprintf(temp,"\tcmp     DWORD PTR [rbp-%d], %d",regByte[(yyvsp[(2) - (22)].ival)],(yyvsp[(4) - (22)].ival)-1);
									append(temp,code);
									append("\tsetle   al",code);
									append("\ttest    al, al",code);
									sprintf(temp,"\tjne     .L%d",jumppoint+4);
									jumppoint = jumppoint+6;
									newJump(jumppoint,code);
			}
			else{
					printf("ERROR Type is not match in Int \n");
			}
				
			;}
    break;

  case 74:
#line 601 "calc.y"
    {  int start = reg[(yyvsp[(2) - (11)].ival)];if(type[(yyvsp[(2) - (11)].ival)]==1){
		 for(start;start<(yyvsp[(4) - (11)].ival);start=start+(yyvsp[(5) - (11)].ival))
		{
			if(start%2!=0)
			{
				printf("%d\n",start);
			}
			
			}
		}
		;}
    break;

  case 75:
#line 615 "calc.y"
    {if((yyvsp[(1) - (3)].ival) == (yyvsp[(3) - (3)].ival)){ checkBool = true;};}
    break;

  case 76:
#line 616 "calc.y"
    {if((yyvsp[(1) - (3)].ival) != (yyvsp[(3) - (3)].ival)){ checkBool = true;};}
    break;

  case 77:
#line 617 "calc.y"
    {if((yyvsp[(1) - (3)].ival) > (yyvsp[(3) - (3)].ival)){ checkBool = true;};}
    break;

  case 78:
#line 618 "calc.y"
    {if((yyvsp[(1) - (3)].ival) >= (yyvsp[(3) - (3)].ival)){ checkBool = true;};}
    break;

  case 79:
#line 619 "calc.y"
    {if((yyvsp[(1) - (3)].ival) < (yyvsp[(3) - (3)].ival)){ checkBool = true;};}
    break;

  case 80:
#line 621 "calc.y"
    {if(type[(yyvsp[(1) - (3)].ival)] == 1){if(reg[(yyvsp[(1) - (3)].ival)] == (yyvsp[(3) - (3)].ival)){ checkBool = true;}
		  		char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(1) - (3)].ival)],(yyvsp[(3) - (3)].ival));
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);
		} else{printf("ERROR Not math type\n");};}
    break;

  case 81:
#line 629 "calc.y"
    {if(type[(yyvsp[(1) - (3)].ival)] == 1){if(reg[(yyvsp[(1) - (3)].ival)] != (yyvsp[(3) - (3)].ival)){ checkBool = true;}
	  			char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(1) - (3)].ival)],(yyvsp[(3) - (3)].ival));
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);
	  }else{printf("ERROR Not math type\n");};}
    break;

  case 82:
#line 637 "calc.y"
    {if(type[(yyvsp[(1) - (3)].ival)] == 1){if(reg[(yyvsp[(1) - (3)].ival)] > (yyvsp[(3) - (3)].ival)){ checkBool = true;}
	  			char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(1) - (3)].ival)],(yyvsp[(3) - (3)].ival));
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);
	  }else{printf("ERROR Not math type\n");};}
    break;

  case 83:
#line 644 "calc.y"
    {if(type[(yyvsp[(1) - (3)].ival)] == 1){if(reg[(yyvsp[(1) - (3)].ival)] >= (yyvsp[(3) - (3)].ival)){ checkBool = true;}
	  			char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(1) - (3)].ival)],(yyvsp[(3) - (3)].ival)-1);
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);
	  }else{printf("ERROR Not math type\n");};}
    break;

  case 84:
#line 651 "calc.y"
    {if(type[(yyvsp[(1) - (3)].ival)] == 1){if(reg[(yyvsp[(1) - (3)].ival)] < (yyvsp[(3) - (3)].ival)){ checkBool = true;}
	  			char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(1) - (3)].ival)],(yyvsp[(3) - (3)].ival)-1);
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);
	  }else{printf("ERROR Not math type\n");};}
    break;

  case 85:
#line 658 "calc.y"
    {if(type[(yyvsp[(1) - (3)].ival)] == 1){if(reg[(yyvsp[(1) - (3)].ival)] <= (yyvsp[(3) - (3)].ival)){ checkBool = true;}
	  			char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(1) - (3)].ival)],(yyvsp[(3) - (3)].ival));
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);
	  }else{printf("ERROR Not math type\n");};}
    break;

  case 86:
#line 665 "calc.y"
    {if(type[(yyvsp[(1) - (3)].ival)] == type[(yyvsp[(3) - (3)].ival)])
	  {if(checkRegEqual((yyvsp[(1) - (3)].ival),(yyvsp[(3) - (3)].ival))){ checkBool = true;
	  			char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(1) - (3)].ival)]);
				append(temp,code);
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(3) - (3)].ival)]);
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);

	  }

	  }else{printf("ERROR Not math type\n");};}
    break;

  case 87:
#line 679 "calc.y"
    {if(type[(yyvsp[(1) - (3)].ival)] == type[(yyvsp[(3) - (3)].ival)])
		  {
			  if(checkRegEqual((yyvsp[(1) - (3)].ival),(yyvsp[(3) - (3)].ival)))
		  		 checkBool = false;
				   else
				   checkBool =true;
				   char temp[100];
					sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(1) - (3)].ival)]);
					append(temp,code);
					sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[(yyvsp[(3) - (3)].ival)]);
					append(temp,code);
					append("\tje     .L2",code);

			  }
			  else
			  {	printf("ERROR Not math type\n");
			  	}
			  ;}
    break;

  case 88:
#line 697 "calc.y"
    {if(type[(yyvsp[(1) - (3)].ival)] == 2){if(regChar[(yyvsp[(1) - (3)].ival)] == (yyvsp[(3) - (3)].id)){ checkBool = true;}}else{printf("ERROR Not math type\n");};}
    break;

  case 89:
#line 698 "calc.y"
    {if(type[(yyvsp[(1) - (3)].ival)] == 2){if(regChar[(yyvsp[(1) - (3)].ival)] != (yyvsp[(3) - (3)].id)){ checkBool = true;}}else{printf("ERROR Not math type\n");};}
    break;

  case 90:
#line 699 "calc.y"
    {if(type[(yyvsp[(1) - (3)].ival)] == 3){if(!strcmp(regString[(yyvsp[(1) - (3)].ival)], (yyvsp[(3) - (3)].s))){ checkBool = true;}}else{printf("ERROR Not math type\n");};}
    break;

  case 91:
#line 700 "calc.y"
    {if(type[(yyvsp[(1) - (3)].ival)] == 3){if(strcmp(regString[(yyvsp[(1) - (3)].ival)], (yyvsp[(3) - (3)].s))){ checkBool = false;}else{ checkBool = true;}}else{printf("ERROR Not math type\n");};}
    break;

  case 92:
#line 701 "calc.y"
    {if((yyvsp[(1) - (3)].ival)!=(yyvsp[(3) - (3)].ival)){ checkBool = true;}else{ checkBool = false;};}
    break;


/* Line 1267 of yacc.c.  */
#line 2597 "calc.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 704 "calc.y"

int updateAnswer(int number)
{
	answer = number;
}

int LoadValue(char c,int number)
{	
	
	reg[c] = number;
	
	return 0;
}

void LoadValueChar(char c,char assgin)
{
	regChar[c] = assgin;

}

void LoadValueString(char c,char *s)
{
	regString[c] = s;
}



int LoadReg(char c1,char c2) //นำค่าตัวแปรหนึ่งใส่อีกตัวแปรหนึ่ง
{
	type[c1] == type[c2];
	if(type[c1] == 1)
	{
		reg[c1] = reg[c2];
		char temp[100];
		sprintf(temp,"\tmov     eax, DWORD PTR [rbp-%d]",regByte[c2]);
		append(temp,code);
		regByte[c1] = ((count_byte%4)+2)*4;
		sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",regByte[c1]);
	    append(temp,code);
		count_byte = regByte[c1];

	}
	else if(type[c1] == 2)
	{
		regChar[c1] = regChar[c2];
		char temp[100];
		sprintf(temp,"\tmov     eax, BYTE PTR [rbp-%d]",regByte[c2]);
		append(temp,code);
		regByte[c1] = count_byte+1;
		sprintf(temp,"\tmov     BYTE PTR [rbp-%d], eax",regByte[c1]);
	    append(temp,code);
		count_byte = regByte[c1];

	}
	else if(type[c1] == 3)
	{
		regString[c2] = regString[c1];
		char temp[100];
		sprintf(temp,"\tmov     rax, QWORD PTR [rbp-%d]",regByte[c2]);
		append(temp,code);
		regByte[c1] = (abs(count_byte-8)+1)*8;
		sprintf(temp,"\tmov     QWORD PTR [rbp-%d], eax",regByte[c1]);
	    append(temp,code);
		count_byte = regByte[c1];
	}

	return 0;
}





bool checkRegEqual(char a,char b)
{
	if(type[a] == 1)
	{
		if(reg[a] == reg[b])
			return true;
	}
	if(type[a] == 2)
	{
		if(regChar[a] == regChar[b])
			return true;
	}
	if(type[a] == 3)
	{
		if(strcmp(regString[a],regString[b]))
			return false;
			else
			return true;
	}
	return false;

}


int getRegValue(char c)
{
	if(type[c] == 1)
	{
		return reg[c];
	}

	return 0;

}

int showRegister(char c)
{
	if(type[c] == 1)
	{
		printf(" %d\n",reg[c]);
		
			char temp[100];
			sprintf(temp,".LC%d",countdata);
			append(temp,data);
			append("\t.string %d",data);
			sprintf(temp,"\tmov     eax, DWORD PTR [rbp-%d]",regByte[c]);
			append(temp,code);
			append("\tmov     esi, eax",code);
			sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
			append(temp,code);
			append("\tmov     eax, 0",code);
			append("\tcall    printf",code);
	

	}
	else if(type[c] == 2)
	{
		printf("= %c\n",regChar[c]);
		char temp[100];
		sprintf(temp,"\tmovsx     eax,BYTE PTR [rbp-%d], %d",regByte[c]);
		append(temp,code);
		append("\tmov     edi, eax",code);
		append("\tcall    putchar",code);
	}
	else if(type[c] == 3)
	{
			
	
			printf("%s\n",regString[c]);
			char temp[100];
			sprintf(temp,".LC%s",countdata);
			append(temp,data);
			append("\t.string %d",data);
			sprintf(temp,"\tmov     eax, QWORD PTR [rbp-%d]",regByte[c]);
			append(temp,code);
			append("\tmov    	rsi, rax",code);
			sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
			append(temp,code);
			append("\tmov     eax, 0",code);
			append("\tcall    printf",code);

	}
	else if(type[c] == 4)
	{
		printf("= %f\n",regFloat[c]);
	}
	else 
	printf("Error the register is NULL\n");
	

	return 0;
}
void ChangeString(char *s)
{
	int count = strlen(s);
	int i = 0;
	while(i<= count-1)
	{
		if((s[i] == '$') && (s[i+1] == 'n' ))
		{
			checkString = true;
			s[i] = ' ';
			s[i+1] = '\n';
		}
		i++;
	}
	printf("%s\n",s);
	if(checkString){
					int i = 0;
				while(i<= count-1)
				{
					if((s[i] == '$') && (s[i+1] == 'n' )) //ในกรณีที่อ่านเจอ $n ซึ่งเป็นการขึ้นบรรทัดใหม่
					{
						s[i] = ' ';
						s[i+1] = ' ';
					}
					i++;
				}
		
			char temp[100];
			sprintf(temp,".LC%d",countdata);
			append(temp,data);
			sprintf(temp,"\t.string %s",s);
			append(temp,data);
			sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
			append(temp,code);
			append("\tcall    put",code);
			countdata = countdata +1;

	}

}
void print(node* p)
{
	if(p)
	{
		fwrite(p->data,1,strlen(p->data),fp);
		fwrite("\n", sizeof(char), 1, fp);
		print(p->next);
	}


}



int main(int argc, const char *argv[]) {

	for(int i=0;i<27;i++)
	{
		reg[i] = 0;
		type[i] = 0;
		regByte[i] =0;
		regString[i] = (char*)malloc(100);
		regString[i] = " ";
	}
	data = getnode(" ",NULL);
	code = getnode(".LBB2:",NULL);
	jump = getnode(".L2:",NULL);
	node *j3 = getnode(".L3",NULL);
	printf("%s\n", argv[1]);
    yyin = fopen(argv[1], "r");
	fp = fopen("asm.txt","w");


    if(yyin == NULL){
        printf("invalid input file\n");
    }
	do { 		
		if(yyin  == ' ' || yyin == '\t')
		continue;
		yyparse();
	} while(!feof(yyin));
	node *head = getnode(".Ldebug_abbrev0:",NULL);
	node *tail = getnode(".LBE3:",NULL);
	append("\tmov     eax, 0",tail);
	append("\tleave",tail);
	append(".LCFI2:",tail);
	append("\tret",tail);
	node *h = head;
	node *t = head;
	append(".Ldebug_info0:",t);
	append(".Ldebug_line0:",t);
	append(".Ltext0:",t);
	append("main:",t);
	append(".LFB0:",t);
	append("\tpush    rbp",t);
	append(".LCFI0:",t);
	append("\tmov     rbp, rsp",t);
	print(head);
	print(data);
	print(code);
	print(tail);
	fclose(fp);

	

	return 0;
}
void yyerror(char* s) {
	printf("Syntax error \n");
	yyparse();
}
