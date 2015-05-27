%union {
	int val;

	struct terminal{
		int val;
		char constante[100];
	} *terminal;
}

%{

#include <stdio.h>
#include "lex.c"
#include "tabsimb.c"


void yyerror(char*);
%}

%token  INT FLOAT FUNCTION_BLOCK VAR_INPUT REAL END_VAR VAR_OUTPUT FUZZIFY TERM IGUAL END_FUZZIFY  DEFUZZIFY  END_DEFUZZIFY  IDENTIFIER  TAB  IF
%token  IS  AND	 OR THEN	 END	 END_RULEBLOCK  END_FUNCTION_BLOCK  METHOD  COG  MIN  MAX ACT  ACCU  RULE RULEBLOCK DEFAULT

%type <terminal> constante valor identificador

%start inicio_expressao

%%
constante: INT  { 
			$$ = (struct terminal*) malloc(sizeof(struct terminal));
			$$->val = INT;
			strcpy($$->constante,yytext);
		}


| FLOAT;

identificador: IDENTIFIER { 
			$$ = (struct terminal*) malloc(sizeof(struct terminal));
			$$->val = IDENTIFIER;
			strcpy($$->constante,yytext);
		};

inicio_expressao: FUNCTION_BLOCK IDENTIFIER declaracao_variavel fuzzify defuzzify ruleblock END_FUNCTION_BLOCK;

declaracao_variavel: VAR_INPUT  variavel END_VAR declaracao_variavel
		   | VAR_INPUT  variavel END_VAR 
		   | VAR_OUTPUT variavel END_VAR declaracao_variavel
                   | VAR_OUTPUT variavel END_VAR ;

variavel: IDENTIFIER ':' REAL ';'
	| IDENTIFIER ':' REAL ';'   variavel ;

fuzzify: FUZZIFY IDENTIFIER term END_FUZZIFY fuzzify 
       | FUZZIFY IDENTIFIER term END_FUZZIFY;

term: TERM identificador IGUAL valor ';' {printf("\nTERM %s := %s", $2->constante, $4->constante);}
    | term TERM identificador IGUAL valor ';'  {printf("\nTERM %s := %s", $3->constante, $5->constante);}
    | method
    | default;

valor: '(' constante ',' constante ')'  { $$ = (struct terminal*) malloc(sizeof(struct terminal));
					  sprintf($$->constante, "(%s, %s)", $2->constante, $4->constante);
					}
     | valor '(' constante ',' constante ')'  {$$ = (struct terminal*) malloc(sizeof(struct terminal)); 
					       sprintf($$->constante, "%s (%s, %s)", $1->constante, $3->constante, $5->constante);
					};

defuzzify: DEFUZZIFY IDENTIFIER   term END_DEFUZZIFY defuzzify
	 | DEFUZZIFY IDENTIFIER   term   method END_DEFUZZIFY
	 | DEFUZZIFY IDENTIFIER   term   method   default END_DEFUZZIFY
	 | DEFUZZIFY IDENTIFIER   term   default END_DEFUZZIFY;

method: METHOD ':' COG ';'
      | METHOD ':' COG ';' method;

default: DEFAULT IGUAL INT';'
       | DEFAULT IGUAL INT';'   default;

ruleblock: RULEBLOCK IDENTIFIER   complemento END_RULEBLOCK;

complemento: and | and complemento | act | act complemento | accu | accu complemento | rule | rule complemento;

and: AND ':' MIN';' | AND ':' MAX';';

act: ACT ':' MIN';' | ACT ':' MAX';';

accu: ACCU ':' MIN';' | ACCU ':' MAX';';

rule: RULE INT ':' IF IDENTIFIER IS IDENTIFIER OR IDENTIFIER IS IDENTIFIER THEN IDENTIFIER IS IDENTIFIER ';'
    | RULE INT ':' IF IDENTIFIER IS IDENTIFIER AND IDENTIFIER IS IDENTIFIER THEN IDENTIFIER IS IDENTIFIER ';'
    | RULE INT ':' IF IDENTIFIER IS IDENTIFIER THEN IDENTIFIER IS IDENTIFIER ';';


%%


extern char *yytext;
extern int column;

void yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\nlinha: %d %s - %s\n", linha, yytext, s);
}


int main()
{
  yyin = fopen("fuzzy.fcl","r");
  inicializa_lista();
  yyparse();

  print_simbolos_lista();
return (0);
}


