/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 81 "calc.y"
{
	char* s;
	int ival;
	float fval;
	char id;
}
/* Line 1529 of yacc.c.  */
#line 146 "calc.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

