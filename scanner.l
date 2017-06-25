%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput

%{
#include "bt.h"
#include "parser.h"
#include "literalsTable.h"

extern LiteralsTable *lt;

%}

%x comment
%option yylineno

%%
<INITIAL,comment>"\n" 		   {} /* Bloco 5: comentarios e caracteres não significativos */
"//".*\n					   {}
"/\*"                    	   { BEGIN(comment); }
<comment>[^*\n]*        	   {}
<comment>"*"+[^*/\n]* 		   {}
<comment>"*"+"/"        	   { BEGIN(INITIAL); }

"if"                     	   { yylval = create_node(IF_NODE); return IF; } /* Bloco 1: Palavras reservadas */
"else"                   	   { yylval = create_node(ELSE_NODE); return ELSE; }
"input"						   { yylval = create_node(INPUT_NODE); return INPUT;}
"int"						   { yylval = create_node(INT_NODE); return INT;}
"void"						   { yylval = create_node(VOID_NODE); return VOID; }
"output"                       { yylval = create_node(OUTPUT_NODE); return OUTPUT; }
"write"                        { yylval = create_node(WRITE_NODE); return WRITE; }
"while" 	               	   { yylval = create_node(WHILE_NODE); return WHILE; }
"return"					   { yylval = create_node(RETURN_NODE); return RETURN; }

"+"   				           { yylval = create_node(PLUS_NODE); return PLUS; } /* Bloco 2: Operadores aritméticos e de comparação */
"-"   				           { yylval = create_node(MINUS_NODE); return MINUS; }
"*"   				           { yylval = create_node(TIMES_NODE); return TIMES; }
"/"   				           { yylval = create_node(OVER_NODE); return OVER; }
"<"   				           { yylval = create_node(LT_NODE); return LT; }
"<="   				           { yylval = create_node(LEQ_NODE); return LE; }
">"   				           { yylval = create_node(GT_NODE); return GT; }
">="   				           { yylval = create_node(GEQ_NODE); return GE; }
"=="   				           { yylval = create_node(EQ_NODE); return EQ; }
"!="   				           { yylval = create_node(NEQ_NODE); return NEQ; }
"="		                   	   { yylval = create_node(ASSIGN_NODE); return ASSIGN; }

";"   				           { return SEMI; } /* Bloco 3: Caracteres especiais */
","   				           { return COMMA; }
"("   				           { return LPAREN; }
")"   				           { return RPAREN; }
"["   				           { return LBRACK; }
"]"   				           { return RBRACK; }
"{"   				           { return LBRACE; }
"}"   				           { return RBRACE; }

[0-9]+                   	   { yylval = create_lit_node(NUM_NODE, -1, yytext); return NUM; } /* Bloco 4: tokens que admitem mais de um lexema */
[A-Za-z][A-Za-z0-9]*     	   { yylval = create_lit_node(ID_NODE, -1, yytext); return ID; }
\"([^\"]*)\"             	   { yylval = create_lit_node(STRING_NODE, add_literal(lt, yytext), yytext); return STRING; }
	   
[ \n\t]+                 	   { }	   
.                        	   { printf("SCANNING ERROR (%d): Unknown symbol %s\n", yylineno, yytext); exit(0); }
