
/* Options to bison */
// File name of generated parser.
%output "parser.c"
// Produces a 'parser.h'
%defines "parser.h"
// Give proper error messages when a syntax error is found.
%define parse.error verbose
// Enable LAC (lookahead correction) to improve syntax error handling.
%define parse.lac full

%{
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int yylex(void);
void yyerror(char const *s);

extern int yylineno;

%}

%define api.value.type {unsigned int}

//Tokens para palavras e caracteres reservados, lacos de repeticao e desvios condicionais
%token INT VOID
%token COMMA SEMI 
%token STRING
%token IF WHILE
%token INPUT OUTPUT WRITE ASSIGN RETURN
%token LPAREN LBRACE LBRACK 
%token NUM ID

//Definicao de regras de precedencia (precedence e left)
%precedence ELSE
%precedence RPAREN
%precedence RBRACE
%precedence RBRACK

%left NEQ EQ LT LE GT GE
%left PLUS MINUS
%left TIMES OVER

%start program

%%

program:
  func-decl-list
;

func-decl-list:
  func-decl-list func-decl
| func-decl
;

func-decl:
  func-header func-body
;

func-header:
  ret-type ID LPAREN params RPAREN
;

func-body:
  LBRACE opt-var-decl opt-stmt-list RBRACE
;

opt-var-decl:
  %empty
| var-decl-list
;

ret-type:
  INT
| VOID
;

params:
  VOID
| param-list
;

param-list:
  param-list COMMA param
| param
;

param:
  INT ID
| INT ID LBRACK RBRACK
;

var-decl-list:
  var-decl-list var-decl
| var-decl
;

var-decl:
  INT ID SEMI
| INT ID LBRACK NUM RBRACK SEMI

block:
  LBRACE opt-stmt-list RBRACE
;

opt-stmt-list: 
  %empty
| stmt-list
;

stmt-list:
  stmt-list stmt
| stmt
;

stmt:
  assign-stmt
| if-stmt
| while-stmt
| return-stmt
| func-call SEMI
;

assign-stmt:
  lval ASSIGN arith-expr SEMI
;

lval:
  ID
| ID LBRACK NUM RBRACK
| ID LBRACK ID RBRACK
;

if-stmt:
  IF LPAREN bool-expr RPAREN block
| IF LPAREN bool-expr RPAREN block ELSE block
;

while-stmt:
  WHILE LPAREN bool-expr RPAREN block
;

return-stmt:
  RETURN SEMI
| RETURN arith-expr SEMI
;

func-call:
  output-call
| write-call
| user-func-call
;

input-call:
  INPUT LPAREN RPAREN
;

output-call:
  OUTPUT LPAREN arith-expr RPAREN
;

write-call:
  WRITE LPAREN STRING RPAREN
;

user-func-call:
  ID LPAREN opt-arg-list RPAREN
;

opt-arg-list:
  %empty
| arg-list
;

arg-list:
  arg-list COMMA arith-expr
| arith-expr
;

//Regra foi unificada para eliminar shift-reduce
bool-expr: arith-expr LT arith-expr
| arith-expr LE arith-expr
| arith-expr GT arith-expr
| arith-expr GE arith-expr
| arith-expr EQ arith-expr
| arith-expr NEQ arith-expr
;

//Regra foi unificada para eliminar shift-reduce
 arith-expr: NUM
| input-call
| lval
| user-func-call
| LPAREN  arith-expr RPAREN
| arith-expr PLUS  arith-expr
| arith-expr MINUS  arith-expr
| arith-expr TIMES  arith-expr
| arith-expr OVER  arith-expr
;

%%

int main() {
	if(yyparse() == 0){
		printf("PARSE SUCESSFUL!\n");
	}

	return 0;
}

//Trata erro e sai do programa
void yyerror (char const *s) {
	printf("PARSE ERROR (%d): %s\n", yylineno, s);
	exit(0);
}
