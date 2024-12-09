%{
  #include "TS.h"
  #include <stdio.h>
  #include "syntaxique.tab.h" 
	extern nb_ligne;
  extern YYSTYPE yylval;
%}

%x ML_COMMENT

Lettre [a-zA-Z]
Chiffre [0-9] 
IDF {Lettre}({Lettre}|{Chiffre}|_)* 
Icst    [1-9][0-9]*|0
Fcst		0|{Chiffre}*"."{Chiffre}+


%%

"//".*        { printf("Eat up comment at line %d\n", nb_ligne); } 

"/*"          { printf("Eat up comment from line %d ", nb_ligne); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/"    { printf("to line %d\n", nb_ligne); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+		
<ML_COMMENT>"*"			
<ML_COMMENT>"\n"    { nb_ligne += 1; }

import                 return IMPORT;  
Lang.io                return BIB_LANG; 
Math.io                return BIB_MATH;
Programme              return KEY_WORD_Programme;
PDec                   return KEY_WORD_PDec;
InDebut                return START_PG;
InFin                  return FIN_PG;
"{"                    return ACO_R;
"}"                    return ACO_C;

Integer                {
                         yylval.str=strdup("Integer");
                         return TYPE_INT;
                       }
Float                  {
                         yylval.str=strdup("Float");
                         return TYPE_FLOAT;
                       } 
final                  { 
                          yylval.str=strdup("final");
                          return FINAL;
                       }
{IDF}                  {
                          yylval.str = strdup(yytext);
                          if(yyleng > 18){
                            printf("input Size is too long\n");
                            return;
                          }else{
                            InsertI_In_Ts(yytext, "IDF", "/" , "Faux");
                            return Idf;
                          }
                       }
{Icst}                  {
                          yylval.entier=atoi(yytext);
                          char strValue[20];
                          sprintf(strValue, "%d", yylval.entier); // this function help to convert integer too a string 
                          InsertI_In_Ts(strValue, "Const", "Integer" , "Faux");
                          return INT_CONST;
                       }
{Fcst}                  {
                          yylval.Tfloat=atof(yytext);
                          char strValue[20];
                          sprintf(strValue, "%.2f", yylval.Tfloat); // this function help to convert integer too a string 
                          InsertI_In_Ts(strValue, "Const", "Float" , "Faux");
                          return FLOAT_CONST;
                       }

=                     { return Equal; }
;                     { return pvg;   }
,                     { return COMMA; }
"+"|"-"		            { return ADDOP; }
"*"			              { return MULOP; }
"/"			              { return DIVOP; }

"["                   { return L_BRCKET;}
"("                   { return L_PARENT;}
")"                   { return R_PARENT;}
"]"                   { return R_BRCKET;}
"|"                   { return  SEPAR ; }
"<-"                  {  return ASSIGN; }




[ \t]                   /* Skip whitespace */;
[ \n] nb_ligne++ ;
.                     {printf("Error Lexical a ligne %d sur %s \n" , nb_ligne ,yytext);
                      return err;}
%%
