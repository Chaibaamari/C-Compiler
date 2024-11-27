%{
  #include <stdio.h>
  #include "syntaxique.tab.h" 

  int nb_ligne = 1;
%}

Lettre [a-zA-Z]
Chiffre [0-9]
IDF {Lettre}({Lettre}|{Chiffre}|_)* 

%%

import|Import                return IMPORT;  
LANG                   return BIB_LANG; 
MATH                   return BIB_MATH;
Programme              return KEY_WORD_Programme;
PDec                   return KEY_WORD_PDec;
Integer                return TYPE_INT;
Float                  return TYPE_FLOAT;
InDebut                return START_PG;
InFin                  return FIN_PG;
"{"                    return ACO_R;
"}"                    return ACO_C;
{IDF}                  return Idf; 
[;]                    return pvg;
","                    return COMMA;
=                      return Equal;
{Chiffre}                return CONST;


[ \t]                   /* Skip whitespace */;
[ \n] nb_ligne++ ;
.                     {printf("Error Lexical a ligne %d sur %s \n" , nb_ligne ,yytext);
                      return err;}
%%
