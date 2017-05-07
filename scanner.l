%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput
%option yylineno

%{ /* Implementa a linguagem C-Minus */
#include "parser.h"

#define process_token(type)return type

void imprimir(int linha, char* lexema, char* token){
    printf("%d: %s -> %s\n", linha, lexema, token);
}

%}

%x comment


%%
<INITIAL,comment>"\n" 	{} /* Bloco 5: comentarios e caracteres não significativos */
"//".*\n					{} 
"/*"                    BEGIN(comment);
<comment>[^*\n]*        {}
<comment>"*"+[^*/\n]* 	{}
<comment>"*"+"/"        BEGIN(INITIAL);
[ \n]+                  {}


"else"                  { process_token(ELSE); }  /* Bloco 1: Palavras reservadas */
"if"                    { process_token(IF); }
"input"                 { process_token(INPUT); }
"int"                  	{ process_token(INT); }
"output"                { process_token(OUTPUT); }
"return"                { process_token(RETURN); }
"void"					{ process_token(VOID); }
"while"					{ process_token(WHILE); }
"write"					{ process_token(WRITE); }

"+"                     { process_token(PLUS); } /* Bloco 2: Operadores aritméticos e de comparação */
"-"                     { process_token(MINUS); }
"*"                     { process_token(TIMES); }
"/"                     { process_token(OVER); }
"<"                     { process_token(LT); }
"<="                    { process_token(LE); }
">"						{ process_token(GT); }
">="					{ process_token(GE); }
"=="                    { process_token(EQ); }
"!="                    { process_token(NEQ); }
"="                   	{ process_token(ASSIGN); }

";"                     { process_token(SEMI); } /* Bloco 3: Caracteres especiais */
","                     { process_token(COMMA); }
"("                     { process_token(LPAREN); }
")"                     { process_token(RPAREN); }
"["						{ process_token(LBRACK); }
"]"						{ process_token(RBRACK); }
"{"						{ process_token(LBRACE); }
"}"						{ process_token(RBRACE); }

[0-9]+                  { process_token(NUM); } /* Bloco 4: tokens que admitem mais de um lexema */
[A-Za-z][A-Za-z0-9]*    { process_token(ID); }
\"([^\"]*)\"			{ process_token(STRING); }

.                       { printf("SCANNING ERROR (%d): Unknown symbol %s\n", yylineno, yytext); exit(0); }

%%
