%{
  #include "TS.h"
  #include <stdio.h>
  #include "syntaxique.tab.h" 
	extern nb_ligne;
  extern YYSTYPE yylval;
%}

Lettre [a-zA-Z]
Chiffre [0-9]
IDF {Lettre}({Lettre}|{Chiffre}|_)* 
cst [1-9][0-9]*|0

%%

import                 return IMPORT;  
Lang.io                 return BIB_LANG; 
Math.io                 return BIB_MATH;
Programme              return KEY_WORD_Programme;
PDec                   return KEY_WORD_PDec;
Integer                {
                         yylval.str=strdup("Integer");
                         return TYPE_INT;
                       }
Float                  {
                         yylval.str=strdup("Float");
                         return TYPE_FLOAT;
                       }
InDebut                return START_PG;
InFin                  return FIN_PG;
"{"                    return ACO_R;
"}"                    return ACO_C; 
{IDF}                  {
                          printf("IDF : ");
                          printf("%s\n", yylval.str = strdup(yytext));
                          InsertI_In_Ts(yytext, "IDF", "/" , true);
                          return Idf;
                       }
{cst}                  {
                          yylval.entier=atoi(yytext);
                          printf("La valeur est : ");
                          char strValue[20];
                          sprintf(strValue, "%d", yylval.entier); // this function help to convert integer too a string 
                          InsertI_In_Ts(strValue, "Const", "/" , true);
                          return CONST;
                       }
=                      return Equal;
;                      return pvg;
,                      return COMMA;



[ \t]                   /* Skip whitespace */;
[ \n] nb_ligne++ ;
.                     {printf("Error Lexical a ligne %d sur %s \n" , nb_ligne ,yytext);
                      return err;}
%%
