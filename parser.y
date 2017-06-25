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

void verify_symbol(int, BT*, int, int, int); //verifica simbolo
void new_symbol(int, BT*, int, int, int); //cria novo simbolo (na tabela de variaveis ou funcao, depende do primeiro parametro)

extern int yylineno;
extern char* yytext;

BT *tree; //arvore
SymbolsTable *ft; //tabela de funcoes
SymbolsTable *vt; //tabela de variaveis
//SymbolsTable *vt_aux; //tabela de variaveis auxiliar
LiteralsTable *lt; //tabela de literais

int aridade_declarada = 0; //aridade declarada
int aridade_chamada = 0; //aridade de chamada de funcao
int escopo = 0; //escopo de variavel

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
  ret-type ID LPAREN params RPAREN											{ new_symbol(FUNCTION, $2, yylineno, -1, aridade_declarada); aridade_declarada = 0;  $$ = new_node(FUNC_HEADER_NODE, 3, $1, create_lit_node(ID_NODE, get_symbol_index(ft, $2->text, -1), $2->text), $4); }
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
  VOID																									{ $$ = create_node(PARAM_NODE); }
| param-list																						{ $$ = $1; }
;

param-list:
  param                                                 { $$ = new_node(PARAM_NODE, 1, $1); }
| param-list COMMA param																{ $$ = add_child($$, $3); }
;

param:
  INT ID																								{ aridade_declarada++; new_symbol(VARIABLE, $2, yylineno, escopo, -1); $$ = new_leaf(SVAR_NODE, get_symbol_index(vt, $2->text, escopo)); }
| INT ID LBRACK RBRACK																	{ aridade_declarada++; new_symbol(VARIABLE, $2, yylineno, escopo, -1); $$ = new_leaf(CVAR_NODE, get_symbol_index(vt, $2->text, escopo)); }
;

var-decl-list:
  var-decl																							{ $$ = new_node(VAR_LIST_NODE, 1, $1); }
| var-decl-list var-decl                                { $$ = add_child($$, $2); }
;

var-decl:
  INT ID SEMI																						{ new_symbol(VARIABLE, $2, yylineno, escopo, -1); $$ = new_leaf(SVAR_NODE, get_symbol_index(vt, $2->text, escopo));  }
| INT ID LBRACK NUM RBRACK SEMI													{ new_symbol(VARIABLE, $2, yylineno, escopo, -1); BT* var_dec_node = new_leaf(CVAR_NODE, get_symbol_index(vt, $2->text, escopo)); $$ = add_child(var_dec_node, create_lit_node(NUM_NODE, $4->data, $4->text)); }
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
  ID																										{ verify_symbol(VARIABLE, $1, yylineno, escopo, -1); $$ = new_leaf(SVAR_NODE, get_symbol_index(vt, $1->text, escopo)); }
| ID LBRACK NUM RBRACK																	{ verify_symbol(VARIABLE, $1, yylineno, escopo, -1); }
| ID LBRACK ID RBRACK																		{ verify_symbol(VARIABLE, $1, yylineno, escopo, -1);  verify_symbol(VARIABLE, $3, yylineno, escopo, -1); BT* lval_node = new_leaf(CVAR_NODE, get_symbol_index(vt, $1->text, escopo)); add_child(lval_node, $$ = new_leaf(SVAR_NODE, get_symbol_index(vt, $3->text, escopo))); $$ = lval_node; }
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
  WRITE LPAREN STRING RPAREN														{ $$ = new_node(WRITE_NODE, 1, create_lit_node(STRING_NODE, get_literal_index(lt, $3->text), $3->text)); }
;

user-func-call:
  ID LPAREN opt-arg-list RPAREN													{ verify_symbol(FUNCTION, $1, yylineno, -1, aridade_chamada); aridade_chamada = 0; BT* func_call = new_leaf(FCALL_NODE, get_symbol_index(ft, $1->text, -1)); $$ = add_child(func_call, $3); }
;

opt-arg-list:
  %empty                                                { };
| arg-list																							{ $$ = $1; }
;

arg-list:
  arith-expr																						{ aridade_chamada++; $$ = new_node(ARG_LIST_NODE, 1, $1); }
| arg-list COMMA arith-expr                             { aridade_chamada++; $$ = add_child($$, $3); }
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
  NUM                                                   { $$ = create_lit_node(NUM_NODE, -1, $1->text); }
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
    //vt_aux = create_sym_table();
    ft = create_sym_table();
    lt = create_lit_table();


    if (yyparse() == 0) {
        // printf("PARSE SUCCESSFUL!\n");
        //printf("AST of given expression:\n");
        //print_tree(tree);
        print_dot(tree);
        free_tree(tree);
    }

    free_literals_table(lt);
    free_sym_table(vt);
    free_sym_table(ft);

    return 0;
}

//verifica se simbolo ou funcao ja foram criadas quando sao chamados no codigo
//no caso de funcoes, tambem confere o numero de parametros
void verify_symbol(int type, BT* node, int line, int escopo, int aridade_chamada) {
  if(type == VARIABLE){
		if(!lookup_var(vt, node->text)){
			printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n", line, node->text);
			exit(1);
		}
  }

	if(type == FUNCTION){
		if(!lookup_var(ft, node->text)){
			printf("SEMANTIC ERROR (%d): function '%s' was not declared.\n", line, node->text);
			exit(1);
		}

		int aridade_declarada = get_symbol_arity(ft, node->text);

		if(aridade_chamada != aridade_declarada){
			printf("SEMANTIC ERROR (%d): function '%s' was called with %d arguments but declared with %d parameters.\n", line, node->text, aridade_chamada, aridade_declarada);
			exit(1);
		}
	}
}

//verifica se simbolo ou funcao ja foram criados antes de propriamente cria-los
void new_symbol(int type, BT* node, int line, int escopo, int aridade_declarada) {
  if(type == VARIABLE){
		if (lookup_var(vt, node->text) && escopo == get_symbol_escope(vt, node->text)) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
            line, node->text, get_line(vt, node->text));
        exit(1);
    }

    add_var(vt, node->text, line, escopo, aridade_declarada);
  }

  if(type == FUNCTION){
      if (lookup_var(ft, node->text)) {
        printf("SEMANTIC ERROR (%d): function '%s' already declared at line %d.\n",
            line, node->text, get_line(ft, node->text));
        exit(1);
    }

    add_var(ft, node->text, line, escopo, aridade_declarada);

  }
}

//Trata erro e sai do programa
void yyerror (char const *s) {
	printf("PARSE ERROR (%d): %s\n", yylineno, s);
	exit(0);
}