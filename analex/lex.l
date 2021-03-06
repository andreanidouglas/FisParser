%{
#include <stdio.h>
#include "anasint.h"
int coluna = 0, linha=0;
void erro();

%}

%%
[0-9][0-9]* {return INT;} //INTEIRO
[0-9].([0-9])+ {return FLOAT;}  //REAL
"FUNCTION_BLOCK" {return FUNCTION_BLOCK;}
"VAR_INPUT" {return VAR_INPUT;}
"REAL" {return REAL;}
"END_VAR" {return END_VAR;}
"VAR_OUTPUT" {return VAR_OUTPUT;}
"FUZZIFY" {return FUZZIFY;}
"TERM" {return TERM;}
":=" {return IGUAL;}
"(" {return '(';}
")" {return ')';}
";" {return ';';}
":" {return ':';}
"," {return ',';}
"END_FUZZIFY" {return END_FUZZIFY;}
"DEFUZZIFY" {return DEFUZZIFY;}
"END_DEFUZZIFY" {return END_DEFUZZIFY;}
"IF" {return IF;}
"IS" {return IS;}
"AND" {return AND;}
"OR" {return OR;}
"THEN" {return THEN;}
"END" {return END;}
"RULEBLOCK" {return RULEBLOCK;}
"END_RULEBLOCK" {return END_RULEBLOCK;}
"END_FUNCTION_BLOCK" {return END_FUNCTION_BLOCK;}
"METHOD" {return METHOD;}
"DEFAULT" {return DEFAULT;}
"COG" {return COG;}
"ACT" {return ACT;}
"MIN" {return MIN;}
"MAX" {return MAX;}
"ACCU" {return ACCU;}
"RULE" {return RULE;}
\t {coluna+=4;}
[a-zA-Z][a-zA-Z0-9]* {coluna += yyleng; return IDENTIFIER;}
\n {coluna = 0;linha++;}
"//" {return 0;}
" " { }

. { erro(); }

%%


void erro()
{
	printf("Erro na l:%d c:%d", linha, coluna);
	exit(1);
}
