
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
%}

%define api.value.type {unsigned int}

%token ENTER ID
%token INT VOID
%token COMMA SEMI 
%token NUM STRING

%token IF WHILE

%token LPAREN LBRACE LBRACK 

%token INPUT OUTPUT WRITE ASSIGN RETURN

%precedence ELSE

%precedence RPAREN
%precedence RBRACE
%precedence RBRACK

%left LT LE GT GE EQ NEQ
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

bool-expr:
  arith-expr bool-op arith-expr
;

bool-op:
  LT
| LE
| GT
| GE
| EQ
| NEQ
;

arith-expr:
  arith-expr arith-op arith-expr
| LPAREN arith-expr RPAREN
| lval
| input-call
| user-func-call
| NUM
;

arith-op:
  PLUS
| MINUS
| TIMES
| OVER
;

%%

int main() {
	if(yyparse() == 0){
		printf("PARSE SUCESSFUL!\n");
	}

	return 0;
}


void yyerror (char const *s) {
	//extern int yylineno;
	printf("PARSE ERROR (%d): %s\n", yylineno, s);
}
