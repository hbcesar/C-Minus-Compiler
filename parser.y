/* Options to bison */
// File name of generated parser.
%output "parser.c"
// Produces a 'parser.h'
%defines "parser.h"
// Give proper error messages when a syntax error is found.
%define parse.error verbose
// Enable LAC (lookahead correction) to improve syntax error handling.
%define parse.lac full
// Enable the trace option so that debugging is possible.
%define parse.trace

%{

#include <stdio.h>
#include <stdlib.h>
#include "bt.h"
#include "literalsTable.h"
#include "symbolsTable.h"

#define VARIABLE 0
#define FUNCTION 1

int yylex(void);
void yyerror(char const *s);

void verify_symbol(int, BT*, int, int, int);
void new_symbol(int, BT*, int, int, int);

extern int yylineno;

BT *tree;
SymbolsTable *ft;
SymbolsTable *vt;
LiteralsTable *lt;

int aridadeDeclarada = 0;
int aridadeChamada = 0;
int escopo = 0;

%}

%define api.value.type {BT*} // Type of variable yylval;

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
  func-decl-list																				{ tree = $1; }
;

func-decl-list:
  func-decl																							{ $$ = new_node(FUNC_DECL_LIST_NODE, 1, $1); }
| func-decl-list func-decl                              { $$ = add_child($$, $2); }
;

func-decl:
	func-header func-body																  { escopo++; $$ = new_node(FUNC_DECL_NODE, 2, $1, $2); }
;

func-header:
  ret-type ID LPAREN params RPAREN											{ new_symbol(FUNCTION, $2, yylineno, -1, aridadeDeclarada); aridadeDeclarada = 0;  $$ = new_node(FUNC_HEADER_NODE, 3, $1, new_leaf(ID_NODE, get_symbol_index(ft, get_name(ft, $2->data), -1)), $4); }
;

func-body:
  LBRACE opt-var-decl opt-stmt-list RBRACE							{ $$ = new_node(FUNC_BODY_NODE, 2, $2, $3); }
;

opt-var-decl:
  %empty																								{ $$ = new_node(VAR_LIST_NODE, 0); };
| var-decl-list																					{ $$ = $1; }
;

ret-type:
  INT																										{ $$ = create_node(INT_NODE); }
| VOID																									{ $$ = create_node(VOID_NODE); }
;

params:
  VOID																									{ $$ = create_node(VOID_NODE); }
| param-list																						{ $$ = $1; }
;

param-list:
  param                                                 { $$ = new_node(PARAM_NODE, 1, $1); }
| param-list COMMA param																{ $$ = add_child($$, $3); }
;

param:
  INT ID																								{ aridadeDeclarada++; new_symbol(VARIABLE, $2, yylineno, escopo, -1); $$ = new_leaf(SVAR_NODE, get_symbol_index(vt, get_name(vt, $2->data), escopo)); }
| INT ID LBRACK RBRACK																	{ aridadeDeclarada++; new_symbol(VARIABLE, $2, yylineno, escopo, -1); $$ = new_leaf(CVAR_NODE, get_symbol_index(vt, get_name(vt, $2->data), escopo)); }
;

var-decl-list:
  var-decl																							{ $$ = new_node(VAR_LIST_NODE, 1, $1); }
| var-decl-list var-decl                                { $$ = add_child($$, $2); }
;

var-decl:
  INT ID SEMI																						{ new_symbol(VARIABLE, $2, yylineno, escopo, -1); $$ = new_leaf(SVAR_NODE, get_symbol_index(vt, get_name(vt, $2->data), escopo));  }
| INT ID LBRACK NUM RBRACK SEMI													{ new_symbol(VARIABLE, $2, yylineno, escopo, -1); BT* var_dec_node = new_leaf(CVAR_NODE, get_symbol_index(vt, get_name(vt, $2->data), escopo)); $$ = add_child(var_dec_node, new_leaf(NUM_NODE, $4->data)); }
;

block:
  LBRACE opt-stmt-list RBRACE														{ $$ = $2; }
;

opt-stmt-list:
  stmt-list                                             { }                                            
;

stmt-list:
  %empty																								{ $$ = new_node(STMT_LIST_NODE, 0); }
| stmt-list stmt																				{ $$ = add_child($$, $2); }
;

stmt:
  assign-stmt																						{ $$ = $1; }
| if-stmt																								{ $$ = $1; }
| while-stmt																						{ $$ = $1; }
| return-stmt																						{ $$ = $1; }
| func-call SEMI																				{ $$ = $1; }
;

assign-stmt:
  lval ASSIGN arith-expr SEMI														{ $$ = new_node(ASSIGN_NODE, 2, $1, $3); }
;

lval:
  ID																										{ verify_symbol(VARIABLE, $1, yylineno, escopo, -1); $$ = new_leaf(SVAR_NODE, get_symbol_index(vt, get_name(vt, $1->data), escopo)); }
| ID LBRACK NUM RBRACK																	{ verify_symbol(VARIABLE, $1, yylineno, escopo, -1); }
| ID LBRACK ID RBRACK																		{ verify_symbol(VARIABLE, $1, yylineno, escopo, -1);  verify_symbol(VARIABLE, $3, yylineno, escopo, -1); BT* lval_node = new_leaf(CVAR_NODE, get_symbol_index(vt, get_name(vt, $1->data), escopo)); add_child(lval_node, $$ = new_leaf(SVAR_NODE, get_symbol_index(vt, get_name(vt, $3->data), escopo))); $$ = lval_node; }
;

if-stmt:
  IF LPAREN bool-expr RPAREN block											{ $$ = new_node(IF_NODE, 2, $3, $5); }
| IF LPAREN bool-expr RPAREN block ELSE block						{ $$ = new_node(IF_NODE, 3, $3, $5, $7); }
;

while-stmt:
  WHILE LPAREN bool-expr RPAREN block										{ $$ = new_node(WHILE_NODE, 2, $3, $5); }
;

return-stmt:
  RETURN SEMI																						{ $$ = new_node(RETURN_NODE, 0); }
| RETURN arith-expr SEMI																{ $$ = new_node(RETURN_NODE, 1, $2); }
;

func-call:
  output-call																						{ $$ = $1; }
| write-call																						{ $$ = $1; }
| user-func-call																				{ $$ = $1; }
;

input-call:
  INPUT LPAREN RPAREN																		{ $$ = $1; }
;

output-call:
  OUTPUT LPAREN arith-expr RPAREN												{ $$ = new_node(OUTPUT_NODE, 1, $3); }
;

write-call:
  WRITE LPAREN STRING RPAREN														{ $$ = new_node(WRITE_NODE, 1, new_leaf(STRING_NODE, get_literal_index(lt, get_literal(lt, $3->data)))); }
;

user-func-call:
  ID LPAREN opt-arg-list RPAREN													{ verify_symbol(FUNCTION, $1, yylineno, -1, aridadeChamada); aridadeChamada = 0; BT* func_call = new_leaf(FCALL_NODE, get_symbol_index(ft, get_name(ft, $1->data), escopo)); $$ = add_child(func_call, $3); }
;

opt-arg-list:
  %empty                                                { };
| arg-list																							{ $$ = $1; }
;

arg-list:
  arith-expr																						{ aridadeChamada++; $$ = new_node(ARG_LIST_NODE, 1, $1); }
| arg-list COMMA arith-expr                             { aridadeChamada++; $$ = add_child($$, $3); }
;

//Regra foi unificada para eliminar shift-reduce
bool-expr: 
  arith-expr LT arith-expr											        { $$ = new_node(LT_NODE, 2, $1, $3); }
| arith-expr LE arith-expr															{ $$ = new_node(LEQ_NODE, 2, $1, $3); }
| arith-expr GT arith-expr															{ $$ = new_node(GT_NODE, 2, $1, $3); }
| arith-expr GE arith-expr															{ $$ = new_node(GEQ_NODE, 2, $1, $3); }
| arith-expr EQ arith-expr															{ $$ = new_node(EQ_NODE, 2, $1, $3); }
| arith-expr NEQ arith-expr															{ $$ = new_node(NEQ_NODE, 2, $1, $3); }
;

//Regra foi unificada para eliminar shift-reduce
 arith-expr: 
  NUM                                                   { $$ = new_leaf(NUM_NODE, $1->data); }
| input-call																						{ $$ = $1; }
| lval																									{ $$ = $1; }
| user-func-call																				{ $$ = $1; }
| LPAREN arith-expr RPAREN															{ $$ = $2; }
| arith-expr PLUS arith-expr														{ $$ = new_node(PLUS_NODE, 2, $1, $3); }
| arith-expr MINUS arith-expr													  { $$ = new_node(MINUS_NODE, 2, $1, $3); }
| arith-expr TIMES arith-expr													  { $$ = new_node(TIMES_NODE, 2, $1, $3); }
| arith-expr OVER arith-expr														{ $$ = new_node(OVER_NODE, 2, $1, $3); }
;

%%

int main() {
    yydebug = 0; // Toggle this variable to enter debug mode.

    vt = create_sym_table();
    ft = create_sym_table();
    lt = create_lit_table();


    if (yyparse() == 0) {
        printf("PARSE SUCCESSFUL!\n");
        //printf("AST of given expression:\n");
        //print_tree(tree);
        //print_dot(tree);
        free_tree(tree);
    }

    free_literals_table(lt);
    free_sym_table(vt);
    free_sym_table(ft);

    return 0;
}

//precisa recriar as funcoes aqui chamadas, ex getSymbol name vai usar das funcoes lookup_var e get_name da biblioteca que o prof deu
void verify_symbol(int type, BT* node, int line, int escopo, int aridadeChamada) {
  char* node_name = node2str(node);

  if(type == VARIABLE){
		if(!lookup_var(vt, node_name)){
			printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n", line, node_name);
			exit(1);
		}
  }

	if(type == FUNCTION){
		if(!lookup_var(ft, node_name)){
			printf("SEMANTIC ERROR (%d): function '%s' was not declared.\n", line, node_name);
			exit(1);
		}

		int aridadeDeclarada = get_symbol_arity(ft, node_name);

		if(aridadeChamada != aridadeDeclarada){
			printf("SEMANTIC ERROR (%d): function '%s' was called with %d arguments but declared with %d parameters.\n", line, node_name, aridadeChamada, aridadeDeclarada);
			exit(1);
		}
	}
}

void new_symbol(int type, BT* node, int line, int escopo, int aridadeDeclarada) {
  char* node_name = node2str(node);

  if(type == VARIABLE){
		if (lookup_var(vt, node_name) && escopo == get_symbol_escope(vt, node_name)) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
            line, node_name, lookup_var(vt, node_name));
        exit(1);
    }

    add_var(vt, node_name, line, escopo, aridadeDeclarada);
  }

  if(type == FUNCTION){
      if (lookup_var(ft, node_name)) {
        printf("SEMANTIC ERROR (%d): function '%s' already declared at line %d.\n",
            line, node_name, lookup_var(ft, node_name));
        exit(1);
    }

    add_var(ft, node_name, line, escopo, aridadeDeclarada);

  }
}

//Trata erro e sai do programa
void yyerror (char const *s) {
	printf("PARSE ERROR (%d): %s\n", yylineno, s);
	exit(0);
}

//tem que rever os vt e ft, tinha colocado tudo um só