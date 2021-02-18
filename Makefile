all: lex yacc
	g++ lex.yy.c y.tab.c -ll -o project

yacc: proje.y
	yacc -d proje.y

lex: proje.l
	lex proje.l
clean: 
	rm lex.yy.c y.tab.c  y.tab.h  proje
