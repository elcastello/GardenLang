SRC = src/
BUILD = build/
CFLAGS = -Wall -g

all: compile

compile: bison lex tree list main tac
	gcc ${CFLAGS} -lfl ${BUILD}tree.o ${SRC}lex.yy.c ${SRC}parser.tab.c ${BUILD}list.o ${BUILD}main.o ${BUILD}tac.o -o ${BUILD}gardenLang

bison:
	bison -dv ${SRC}parser.y -o ${SRC}parser.tab.c

lex:
	lex -o ${SRC}lex.yy.c ${SRC}lexico.lex

tree:
	gcc ${CFLAGS} -c ${SRC}tree.c -o ${BUILD}tree.o

list: bison
	gcc ${CFLAGS} -c ${SRC}list.c -o ${BUILD}list.o

tac: tree list
	gcc ${CFLAGS} -c ${SRC}tac.c -o ${BUILD}tac.o

main:
	gcc ${CFLAGS} -c ${SRC}main.c -o ${BUILD}main.o

run:
	./${BUILD}gardenLang tests/correct.c --dotfile

clean:
	rm ${SRC}*.tab.c ${SRC}*.tab.h
	rm ${SRC}lex.yy.c
	rm ${BUILD}*.o
