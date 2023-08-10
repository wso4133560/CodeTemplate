rm lex.c parser.tab.c parser.tab.h
flex lex.l
bison -d parser.y
g++ lex.c parser.tab.c main.cpp -lfl -o test
