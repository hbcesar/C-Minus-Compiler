
all: bison flex gcc
	@echo "Done."

bison: parser.y
	bison -v parser.y

flex: scanner.l
	flex scanner.l

gcc: scanner.c parser.c bt.c litTable.c symTable.c
	gcc -Wall -o trab3 scanner.c parser.c litTable.c symTable.c bt.c -ly 
	./trab3 < in/c02.cm 

clean:
	@rm -f *.o *.output scanner.c parser.h parser.c parser *.dot *.pdf
