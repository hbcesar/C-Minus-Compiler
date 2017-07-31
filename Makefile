
all: bison flex gcc
	@echo "Done."

bison: parser.y
	bison -v parser.y

flex: scanner.l
	flex scanner.l

gcc: scanner.c parser.c bt.c litTable.c symTable.c interpreter.c
	gcc -Wall -o trab4 scanner.c parser.c litTable.c symTable.c bt.c interpreter.c -ly

clean:
	@rm -f *.o *.output scanner.c parser.h parser.c parser *.dot *.pdf
