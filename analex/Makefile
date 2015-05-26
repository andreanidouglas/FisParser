all:
	lex -o lex.c lex.l
	yacc -o anasint.c anasint.y -d
	gcc -Wall -o anasint anasint.c -lfl
