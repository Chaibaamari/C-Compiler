%{
  #include <stdio.h>
  #include "syntaxique.tab.h" 
%}
%token BIB_LANG IMPORT BIB_MATH pvg err Idf FIN_PG COMMA ACO_R ACO_C ;
%token START_PG TYPE_FLOAT TYPE_INT KEY_WORD_PDec KEY_WORD_Programme Equal CONST ;

%%
  Z: IMP PROD_D ACO_R P_DECL ACO_C
  {
    printf("Assignment successful\n");
    YYACCEPT;
  }
;

IMP: IMPORT BIB
   | /* epsilon (empty alternative) */
;

BIB: BIB_LANG T
   | BIB_MATH T
;

T: pvg IMP
;

PROD_D: KEY_WORD_Programme PROG_NAME
;

PROG_NAME: Idf
         | /* epsilon (empty alternative) */
;

P_DECL: KEY_WORD_PDec TYPE_D DEB
;

TYPE_D: TYPE_INT IDF_NAME
      | TYPE_FLOAT IDF_NAME
      | /* epsilon (empty alternative) */
;

IDF_NAME: Idf NEW
;

NEW: pvg TYPE_D
    | COMMA IDF_NAME
;

DEB: START_PG INSTRUCTION FIN_PG
;

INSTRUCTION: EXP_S 
           | 
;
EXP_S: Idf Equal CONST FIN
;

FIN: pvg  INSTRUCTION
;

%%

main()
{
yyparse(); 
}
syywrap()
{}




