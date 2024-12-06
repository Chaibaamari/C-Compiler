%{
  #include <stdio.h>
  #include "syntaxique.tab.h" 


  int nb_ligne = 1;
  char SaveType[20];
  int trouve;


%}
%union{ 
  int entier;
  char* str;
}

%token BIB_LANG IMPORT BIB_MATH pvg err <str>Idf FIN_PG COMMA ACO_R ACO_C ADDOP MULOP DIVOP ;
%token START_PG <str>TYPE_FLOAT <str>TYPE_INT KEY_WORD_PDec KEY_WORD_Programme Equal <entier>INT_CONST ;
%token R_BRCKET L_BRCKET SEPAR FINAL FLOAT_CONST;


%left MULOP DIVOP
%left ADDOP


%%
Z: IMP PROGRMME_NAME  P_DECL 
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

PROGRMME_NAME: KEY_WORD_Programme PROG_NAME
;

PROG_NAME: Idf
         | /* epsilon (empty alternative) */
;

P_DECL: KEY_WORD_PDec DECLARATIONS DEBUT_PROGRAMME
;

DECLARATIONS : DECLARATIONS DECLARATION
          | DECLARATION
;

DECLARATION: TYPE NAMES pvg
           | FINAL TYPE NAMES pvg
;
NAMES: NAMES SEPAR VARIABLE
     | NAMES SEPAR INIT 
     | VARIABLE  
     | INIT
;
VARIABLE: Idf {
                    InsertType($1 , SaveType);
              } 
        | Idf ARRAY
              {
                    InsertType($1 , SaveType);
              }
;
ARRAY: ARRAY L_BRCKET INT_CONST R_BRCKET
     | L_BRCKET INT_CONST R_BRCKET
;

INIT: Idf Equal INT_CONST 
              {
                    InsertType($1 , SaveType);
              }
    | Idf Equal FLOAT_CONST
              {
                    InsertType($1 , SaveType);
              }
;

TYPE: TYPE_INT   {strcpy(SaveType , $1);}
    | TYPE_FLOAT {strcpy(SaveType , $1);}
;

/* Part Two Of Experssion or affectation line ( x = x + 1 ) OR ( x = x / 12 )...............*/

DEBUT_PROGRAMME: START_PG CORE_PG FIN_PG
;

CORE_PG : INSTRUCTION 
; /*LOOP CONDITION PRINTF*/

INSTRUCTION : EXPERESSION INSTRUCTION
            |
;

EXPERESSION: Idf Equal INT_CONST pvg {
                                 if(!searchFullType(SaveType) == 0){
                                    printf("declare '%s' not found \n" , $1);
                                    YYACCEPT;
                                 }
                                    
}
;

/*
B: Idf 
 | INT_CONST
 | B OP B 
; 
OP : ADDOP
 
   | MULOP
   | DIVOP
;
*/

%%

main()
{
yyparse(); 
displaySymbolTable();
}
syywrap()
{}
int yyerror(char *msg){
  printf("Error syntaxique %d a la ligne %d" , msg , nb_ligne);
}




