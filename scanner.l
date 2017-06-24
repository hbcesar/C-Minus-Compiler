%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput

%{
#include "bt.h"
#include "parser.h"
#include "tables.h"

extern LitTable *lt;

%x comment
%option yylineno

%}

%%
<INITIAL,comment>"\n" 		   {} /* Bloco 5: comentarios e caracteres não significativos */
"//".*\n					   {}
"/*"                    	   BEGIN(comment);
<comment>[^*\n]*        	   {}
<comment>"*"+[^*/\n]* 		   {}
<comment>"*"+"/"        	   BEGIN(INITIAL);
[ \n]+                  	   {}

"if"                     	   { return IF; } /* Bloco 1: Palavras reservadas */
"else"                   	   { return ELSE; }
"input"						   { return INPUT;}
"int"						   { return INT;}
"void"						   { return VOID; }
"output"                       { return OUTPUT;  }
"write"                        { return WRITE; }
"while" 	               	   { return WHILE; }
"return"					   { return RETURN; }

"+"   				           { return PLUS; } /* Bloco 2: Operadores aritméticos e de comparação */
"-"   				           { return MINUS; }
"*"   				           { return TIMES; }
"/"   				           { return OVER; }
"<"   				           { return LT; }
"<="   				           { return LE; }
">"   				           { return GT; }
">="   				           { return GE; }
"=="   				           { return EQ; }
"!="   				           { return NEQ; }
"="		                   	   { return ASSIGN; }

";"   				           { return SEMI; } /* Bloco 3: Caracteres especiais */
","   				           { return COMMA; }
"("   				           { return LPAREN; }
")"   				           { return RPAREN; }
"["   				           { return LBRACK; }
"]"   				           { return RBRACK; }
"{"   				           { return LBRACE; }
"}"   				           { return RBRACE; }

[0-9]+                   	   { return NUMBER; } /* Bloco 4: tokens que admitem mais de um lexema */
[A-Za-z][A-Za-z0-9]*     	   { return ID; }
\"([^\"]*)\"             	   { add_literal(lt, yytext); return STRING; }
	   
.                        	   { printf("SCANNING ERROR (%d): Unknown symbol %s\n", yylineno, yytext); exit(0); }
