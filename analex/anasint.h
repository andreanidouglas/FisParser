/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     FUNCTION_BLOCK = 260,
     VAR_INPUT = 261,
     REAL = 262,
     END_VAR = 263,
     VAR_OUTPUT = 264,
     FUZZIFY = 265,
     TERM = 266,
     IGUAL = 267,
     END_FUZZIFY = 268,
     DEFUZZIFY = 269,
     END_DEFUZZIFY = 270,
     IDENTIFIER = 271,
     TAB = 272,
     IF = 273,
     IS = 274,
     AND = 275,
     OR = 276,
     THEN = 277,
     END = 278,
     END_RULEBLOCK = 279,
     END_FUNCTION_BLOCK = 280,
     METHOD = 281,
     COG = 282,
     MIN = 283,
     MAX = 284,
     ACT = 285,
     ACCU = 286,
     RULE = 287,
     RULEBLOCK = 288,
     DEFAULT = 289
   };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define FUNCTION_BLOCK 260
#define VAR_INPUT 261
#define REAL 262
#define END_VAR 263
#define VAR_OUTPUT 264
#define FUZZIFY 265
#define TERM 266
#define IGUAL 267
#define END_FUZZIFY 268
#define DEFUZZIFY 269
#define END_DEFUZZIFY 270
#define IDENTIFIER 271
#define TAB 272
#define IF 273
#define IS 274
#define AND 275
#define OR 276
#define THEN 277
#define END 278
#define END_RULEBLOCK 279
#define END_FUNCTION_BLOCK 280
#define METHOD 281
#define COG 282
#define MIN 283
#define MAX 284
#define ACT 285
#define ACCU 286
#define RULE 287
#define RULEBLOCK 288
#define DEFAULT 289




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


