%{
  #include <stdio.h>
  #include "syntaxique.tab.h"  


  int nb_ligne = 1;
  char SaveType[20];
  int langBIB = 0;
  int IOBIB = 0;

%}
%union{ 
  int entier;
  char* str;
  float Tfloat;
  struct Node* node;
}

%token BIB_LANG IMPORT BIB_IO pvg err FIN_PG COMMA ACO_R ACO_C ADDOP MULOP DIVOP ;
%token START_PG KEY_WORD_PDec KEY_WORD_Programme Equal PRINT Print_CORE FOR ENDFOR DO;
%token R_BRCKET L_BRCKET SEPAR FINAL ASSIGN L_PARENT R_PARENT ;
%token INCR_OP DECR_OP SUP INF SUP_EG INF_EG NOT_EQUAL REFER;
%token INPUT WRITE <str>FS space IF ELSE ENDIF;
%token <str>TYPE_FLOAT <str>TYPE_INT <str>Idf;
%token <entier>INT_CONST <entier>FLOAT_CONST;
%token <str>core_write;


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

BIB: BIB_LANG {langBIB = 1;} T
   | BIB_IO {IOBIB = 1;} T
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
    |  Idf ARRAY Equal L_BRCKET VALUES R_BRCKET
              {
                handleDeclaration($1, SaveType);
              }
    | Idf Equal Idf
              {
                handleDeclaration($1, SaveType);
                Incompatible_type(getType($1) , getType($3) , nb_ligne);
              }
;



VALUES: VALUES COMMA INT_CONST
      | VALUES COMMA FLOAT_CONST
      | INT_CONST
      | FLOAT_CONST
;

TYPE: TYPE_INT   {strcpy(SaveType , $1);}
    | TYPE_FLOAT {strcpy(SaveType , $1);}
;


DEBUT_PROGRAMME: START_PG STATEMENTS FIN_PG
;

STATEMENTS : STATEMENTS STATEMENT 
           | STATEMENT
; 

STATEMENT : AFFECTATIONS | for_statement | printf_statement | if_statement;  /* LOOP  IF  PRINTF() */


AFFECTATIONS :  Idf ASSIGN AFFECTATION pvg
                    {
                      Non_declare($1);
                      Modify_Const($1);
                      if(langBIB == 0){
                        printf("ERROR : if faut declare le biblioteque 'ISIL_LANG' pour excuter cette opération");
                      }
                    }
;

for_statement: FOR L_PARENT  AFFECTATIONS  EXPRESSION  pvg   AFFECTATION  R_PARENT  DO STATEMENTS ENDFOR
;
if_statement: IF L_PARENT EXPRESSION R_PARENT DO STATEMENTS  optional_else  
;
optional_else: ENDIF
             | ELSE STATEMENTS ENDIF
;
EXPRESSION :  Idf SUP       INT_CONST 
            | Idf INF       INT_CONST 
            | Idf Equal     INT_CONST 
            | Idf SUP_EG    INT_CONST 
            | Idf INF_EG    INT_CONST   
            | Idf NOT_EQUAL INT_CONST
            | Idf REFER     INT_CONST
;

printf_statement: WRITE L_PARENT argumentsWrite argument R_PARENT pvg {
                printf("OK\n");
                }
                 | INPUT { if(IOBIB == 0){
                                   printf("ERROR : if faut declare le biblioteque 'ISIL_IO' pour excuter cette operation\n");
                                    return;}}
                           L_PARENT  argumentsInput  argument  R_PARENT pvg {
                 printf("OK\n");
                }
    ;
argumentsInput : FS argumentsInput 
               | FS 
;
argumentsWrite : core_write argumentsWrite 
          | FS argumentsWrite       
          | FS                   
          | core_write                  
;
argument : argument COMMA Idf 
         |  COMMA Idf 
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
           | Idf INCR_OP
           | Idf DECR_OP

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





