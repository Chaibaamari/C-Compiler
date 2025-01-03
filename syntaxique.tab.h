
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
     BIB_LANG = 258,
     IMPORT = 259,
     BIB_IO = 260,
     pvg = 261,
     err = 262,
     FIN_PG = 263,
     COMMA = 264,
     ACO_R = 265,
     ACO_C = 266,
     ADDOP = 267,
     MULOP = 268,
     DIVOP = 269,
     START_PG = 270,
     KEY_WORD_PDec = 271,
     KEY_WORD_Programme = 272,
     Equal = 273,
     PRINT = 274,
     Print_CORE = 275,
     FOR = 276,
     ENDFOR = 277,
     DO = 278,
     R_BRCKET = 279,
     L_BRCKET = 280,
     SEPAR = 281,
     FINAL = 282,
     ASSIGN = 283,
     L_PARENT = 284,
     R_PARENT = 285,
     ORFER = 286,
     INCR_OP = 287,
     DECR_OP = 288,
     SUP = 289,
     INF = 290,
     SUP_EG = 291,
     INF_EG = 292,
     NOT_EQUAL = 293,
     REFER = 294,
     EQ_OP = 295,
     INPUT = 296,
     WRITE = 297,
     FS = 298,
     space = 299,
     IF = 300,
     ELSE = 301,
     ENDIF = 302,
     NOT = 303,
     TYPE_FLOAT = 304,
     TYPE_INT = 305,
     Idf = 306,
     INT_CONST = 307,
     FLOAT_CONST = 308,
     core_write = 309
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 17 "syntaxique.y"
 
  int entier;
  char* str;
  float Tfloat;
  struct Node* node;



/* Line 1676 of yacc.c  */
#line 115 "syntaxique.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


