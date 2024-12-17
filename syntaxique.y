%{
  #include <stdio.h>
  #include "syntaxique.tab.h"  


  int nb_ligne = 1;
  char SaveType[20];
  int langBIB = 0;
  int IOBIB = 0;
  int checkBIB = 0 ;
  int checkInput = 0 ;
  int checkWrite = 0 ;
  int ValueCount = 0;
  int CurrentArraySize = 0;

%}
%union{ 
  int entier;
  char* str;
  float Tfloat;
  struct Node* node;
}

%token BIB_LANG IMPORT BIB_IO pvg err FIN_PG COMMA ACO_R ACO_C ADDOP MULOP DIVOP ;
%token START_PG KEY_WORD_PDec KEY_WORD_Programme Equal PRINT Print_CORE FOR ENDFOR DO;
%token R_BRCKET L_BRCKET SEPAR FINAL ASSIGN L_PARENT R_PARENT ORFER ;
%token INCR_OP DECR_OP SUP INF SUP_EG INF_EG NOT_EQUAL REFER EQ_OP;
%token INPUT WRITE <str>FS space IF ELSE ENDIF NOT;

%token <str>TYPE_FLOAT <str>TYPE_INT <str>Idf;
%token <entier>INT_CONST <entier>FLOAT_CONST;
%token <str>core_write;


%left MULOP DIVOP
%left ADDOP
%right Equal
%right REFER
%right ORFER
%right INCR_OP
%right DECR_OP
%left SUP
%left INF 
%left SUP_EG 
%left INF_EG
%left NOT_EQUAL
%left EQ_OP
%left COMMA


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

// part of déclaration ---------------------------------------------------------------------------------

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
     | L_BRCKET INT_CONST R_BRCKET  {CurrentArraySize = $2}
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
                depassmentDeTaille(CurrentArraySize , ValueCount , nb_ligne);
              }
    | Idf Equal Idf
              {
                handleDeclaration($1, SaveType);
                Incompatible_type(getType($1) , getType($3) , nb_ligne);
              }
;



VALUES: VALUES COMMA INT_CONST {ValueCount++}
      | VALUES COMMA FLOAT_CONST {ValueCount++}
      | INT_CONST {ValueCount++}
      | FLOAT_CONST {ValueCount++}
;

TYPE: TYPE_INT   {strcpy(SaveType , $1);}
    | TYPE_FLOAT {strcpy(SaveType , $1);}
;

// part of Programme Instruction ---------------------------------------------------------------------------------

DEBUT_PROGRAMME: START_PG STATEMENTS FIN_PG
;

STATEMENTS : STATEMENTS STATEMENT 
           | STATEMENT
; 

STATEMENT : AFFECTATIONS | for_statement | printf_statement | if_statement; 


AFFECTATIONS :  Idf ASSIGN AFFECTATION pvg
                    {
                      Non_declare($1 , nb_ligne);
                      Modify_Const($1);
                      if(langBIB == 0 && checkBIB == 0){
                        printf("Erreur : if faut declare le biblioteque 'ISIL_LANG' pour excuter cette opération");
                        checkBIB = 1;
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

EXPRESSION :  EXPRESSION SUP EXPRESSION
            | EXPRESSION INF EXPRESSION 
            | EXPRESSION Equal EXPRESSION 
            | EXPRESSION SUP_EG EXPRESSION 
            | EXPRESSION INF_EG EXPRESSION   
            | EXPRESSION NOT_EQUAL EXPRESSION
            | EXPRESSION EQ_OP EXPRESSION
            | EXPRESSION REFER  EXPRESSION 
            | EXPRESSION ORFER  EXPRESSION 
            | L_PARENT EXPRESSION R_PARENT
            | NOT Idf 
            | Idf
            | INT_CONST
            | FLOAT_CONST
;

printf_statement: WRITE  L_PARENT core_write  COMMA Idf R_PARENT pvg {
                        if(IOBIB == 0 && checkInput == 0){
                          printf("Erreur Symantique : Pour utiliser 'Input' il faut declare 'ISIL_IO'\n");
                          checkInput = 1;
                        }
                        SymantiqueFormatage($3 , $5 , nb_ligne);
                }
                 | INPUT L_PARENT core_write COMMA Idf  R_PARENT pvg {
                        if(IOBIB == 0 && checkWrite == 0){
                          printf("Erreur Symantique : Pour utiliser 'Write' il faut declare 'ISIL_IO'\n");
                          checkWrite = 1;
                        }
                        SymantiqueFormatage($3 , $5 , nb_ligne);
                }
    ;
/*argument : argument COMMA Idf 
         |  COMMA Idf
;*/

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
int yyErreur (char *msg)
{
  fprintf(stderr, "Syntax Erreur at line %d\n", nb_ligne);
  exit(1);
}





