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
%token R_BRCKET L_BRCKET SEPAR FINAL FLOAT_CONST ASSIGN L_PARENT R_PARENT;


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
/*part of déclaration complete */
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
VARIABLE: Idf 
              {
                handleDeclaration($1, SaveType);
                
              } 
        | Idf ARRAY
              {
                handleDeclaration($1, SaveType);
              }
;
ARRAY: ARRAY L_BRCKET INT_CONST R_BRCKET
     | L_BRCKET INT_CONST R_BRCKET
;

INIT: Idf Equal INT_CONST 
              {
                handleDeclaration($1, SaveType);
              }
    | Idf Equal FLOAT_CONST
              {
                handleDeclaration($1, SaveType);
              }
;

TYPE: TYPE_INT   {strcpy(SaveType , $1);}
    | TYPE_FLOAT {strcpy(SaveType , $1);}
;


DEBUT_PROGRAMME: START_PG CORE_PG FIN_PG
;

CORE_PG : AFFECTATIONS 
; /*LOOP CONDITION PRINTF*/

AFFECTATIONS : AFFECTATIONS Idf ASSIGN AFFECTATION pvg
             | Idf ASSIGN AFFECTATION pvg
;

AFFECTATION: AFFECTATION ADDOP AFFECTATION
           | AFFECTATION MULOP AFFECTATION
           | AFFECTATION DIVOP AFFECTATION 
           | L_PARENT AFFECTATION R_PARENT
           | ADDOP INT_CONST  // SIN NOT FAITE LIKE THIS IS ERROR (-1)
           | ADDOP FLOAT_CONST
           | Idf
           | INT_CONST
           | FLOAT_CONST

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




