%{
#include <stdio.h>
#define INT 256
#define FLOAT 257
#define FUNCTION_BLOCK 258
#define VAR_INPUT 259
#define REAL 260
#define END_VAR 261
#define VAR_OUTPUT 262
#define FUZZIFY 263
#define TERM 264
#define IGUAL 265
#define END_FUZZIFY 266
#define DEFUZZIFY 267
#define END_DEFUZZIFY 268
#define IDENTIFIER 269
#define TAB 270
int coluna = 0, linha=0;
void erro();

%}

%%
[0-9]+ {return INT;} //INTEIRO
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
"END_FUZZIFY" {return END_FUZZIFY;}
"DEFUZZIFY" {return DEFUZZIFY;}
"END_DEFUZZIFY" {return END_DEFUZZIFY;}
\t {return TAB;}
[a-zA-Z][a-zA-Z0-9]* {coluna += yyleng; return IDENTIFIER;}
\n {coluna = 0;linha++;}
"//" {return;}
" " { }

. { erro(); }

%%
int main (int argc, char **argv)
{
	int token;
	yyin = fopen(argv[1], "r");

	token = yylex();
	while (token)
	{
		token = yylex();
		coluna += yyleng;
		printf("%d linha: %d coluna: %d\n", token, linha,coluna);
	}
}

void erro()
{
	printf("Erro na l:%d c:%d", linha, coluna);
	exit(1);
}
