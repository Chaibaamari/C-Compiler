%{
  #include <stdio.h>
  #include "syntaxique.tab.h"  


  int nb_ligne = 1;
  char SaveType[20];


%}
%union{ 
  int entier;
  char* str;
  float Tfloat;
  struct Node* node;
}

%token BIB_LANG IMPORT BIB_MATH pvg err <str>Idf FIN_PG COMMA ACO_R ACO_C ADDOP MULOP DIVOP ;
%token START_PG <str>TYPE_FLOAT <str>TYPE_INT KEY_WORD_PDec KEY_WORD_Programme Equal <entier>INT_CONST <entier>FLOAT_CONST ;
%token R_BRCKET L_BRCKET SEPAR FINAL ASSIGN L_PARENT R_PARENT MIX_CHIFFRE;


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
           | FINAL TYPE Idf Equal INT_CONST  pvg {setConst_Finel($3);handleDeclaration($3, SaveType);}
           | FINAL TYPE Idf Equal FLOAT_CONST  pvg {setConst_Finel($3); handleDeclaration($3, SaveType);}
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
                Incompatible_type(getType($1) , "Integer" , nb_ligne);
              }
    | Idf Equal FLOAT_CONST
              {
                handleDeclaration($1, SaveType);
                Incompatible_type(getType($1) , "Float" , nb_ligne);
              }
    | ARRAY_INIT
;

ARRAY_INIT: Idf ARRAY ASSIGN L_BRCKET VALUES R_BRCKET
;

VALUES: VALUES COMMA MIX_CHIFFRE
      | MIX_CHIFFRE
;

TYPE: TYPE_INT   {strcpy(SaveType , $1);}
    | TYPE_FLOAT {strcpy(SaveType , $1);}
;


DEBUT_PROGRAMME: START_PG STATEMENTS FIN_PG
;

STATEMENTS : STATEMENTS STATEMENT 
           | STATEMENT
; 

STATEMENT : AFFECTATIONS /* LOOP  IF  PRINTF() */


AFFECTATIONS :  Idf ASSIGN AFFECTATION pvg
                    {
                      Non_declare($1);
                      Modify_Const($1);
                    }
;

AFFECTATION: AFFECTATION ADDOP INT_CONST
           | AFFECTATION ADDOP FLOAT_CONST
           | AFFECTATION ADDOP Idf
           | AFFECTATION ADDOP L_PARENT AFFECTATION R_PARENT
           | AFFECTATION MULOP INT_CONST
           | AFFECTATION MULOP FLOAT_CONST
           | AFFECTATION MULOP Idf
           | AFFECTATION MULOP L_PARENT AFFECTATION R_PARENT
           | AFFECTATION DIVOP INT_CONST 
                 {
                    divide_zero($3 , nb_ligne);
                 }
           | AFFECTATION DIVOP Idf
           | AFFECTATION DIVOP L_PARENT AFFECTATION R_PARENT
           | L_PARENT AFFECTATION R_PARENT
           | ADDOP INT_CONST  
           | ADDOP FLOAT_CONST
           | Idf
           | INT_CONST
           | FLOAT_CONST

;


%%

main()
{
yyparse(); 
displaySymbolTable();
}
syywrap()
{}
int yyerror (char *msg)
{
  fprintf(stderr, "Syntax error at line %d\n", nb_ligne);
  exit(1);
}





