#include "interpreter.h"

#include "literalsTable.h"
#include "symbolsTable.h"

#include <stdio.h>
#include <stdlib.h>

extern SymbolsTable *vt;
extern LiteralsTable *lt;

// ------------------------- PILHA ----------------------------------------

#define STACK_SIZE 100

int stack[STACK_SIZE];
int sp = -1; // stack pointer
int op = 0; //offset pointer

void push(int x)
{
	sp++;
	stack[sp] = x;
}

int pop(){
	if(sp == -1) {
		printf("Pop no stack mas nao tem nenhum menino no stack");
		exit(1);
	}

	return stack[sp--];
}

void init_stack() {
	for (int i = 0; i < STACK_SIZE; i++) {
		stack[i] = 0;
	}
}

void print_stack() {
	printf("STACK: ");

	for (int i = 0; i <= sp; i++) {
		printf("%d / ", stack[i]);
	}

	printf("\n");
}

int increment_offset(int n) {
	return op += n;
}


// ------------------------- MEMÓRIA ----------------------------------

#define MEM_SIZE 100

int mem[MEM_SIZE];

void store(int endereco, int val){
	mem[endereco] = val;
}

int load(int endereco){
	return mem[endereco];
}

void init_mem() {
  for (int addr = 0; addr < MEM_SIZE; addr++) {
    mem[addr] = 0;
  }
}


// ------------------------- FUNÇÕES ----------------------------------

void trace_msg(char* msg){
	printf("TRACE: %s\n", msg);
}

void run_func_decl_list(BT* node) {
	//trace_msg("func_decl_list");

	int size = node->children_count;

	for (int i = 0; i < size; i++) {
		rec_run_ast(node->children[i]);
	}
}

void run_func_decl(BT* node) {
	//trace_msg("func_decl");

	rec_run_ast(node->children[0]);
	rec_run_ast(node->children[1]);
}

void run_func_header(BT* node) {
	//trace_msg("func_header");

	int size = node->children_count;
  	if(node->children[size - 1]->kind != VOID_NODE) {
  		rec_run_ast(node->children[size - 1]);
  	}
}

void run_param_list(BT* node) {
	//trace_msg("param_list");
}

void run_func_body(BT* node) {
	//trace_msg("func_body");

	rec_run_ast(node->children[0]); //VAR LIST
	rec_run_ast(node->children[1]); //STMT LIST
}

void run_var_list(BT* node) {
	//trace_msg("var_list");

	int size = node->children_count;

	int i;
	for(i = 0; i < size; i++){
		if(node->children[i]->kind == SVAR_NODE) {
			set_sym_offset(vt, node->children[i]->data, increment_offset(1));
		} else if(node->children[i]->kind == CVAR_NODE) {
			rec_run_ast(node->children[i]->children[0]);
			set_sym_offset(vt, node->children[i]->data, increment_offset(pop()));
		}
	}
}

void run_stmt_list(BT* node) {
	//trace_msg("stmt_list");

	int size = node->children_count;

	for (int i = 0; i < size; i++) {
		rec_run_ast(node->children[i]);
	}
}

void run_input(BT* node) {
	//trace_msg("input");

	int x;
	scanf("%d", &x);
	printf("input: %d\n", x);
	push(x);
}

void run_output(BT* node) {
	//trace_msg("output");

	rec_run_ast(node->children[0]);

	int x = pop();

	printf("%d", x);
}

void run_write(BT* node) {
	//trace_msg("write");

	char *str = (char *)malloc(128 * sizeof(char));

	BT* child = node->children[0];
	
	strcpy(str, get_literal(lt, child->data));
	
	//remove_all_chars(str, '\"');
	//linebreak_replace(str);
	
	printf("%s", str);
}

void run_assign(BT* node) {
	//trace_msg("assign");

	rec_run_ast(node->children[1]);

	if(node->children[0]->kind == SVAR_NODE) {
		int offset = get_sym_offset(vt, node->children[0]->data);
		store(offset, pop());
	} else if(node->children[0]->kind == CVAR_NODE) {
		rec_run_ast(node->children[0]->children[0]);

		int offset = get_sym_offset(vt, node->children[0]->data) + pop();
		store(offset, pop());
	}
}

void run_num(BT* node) {
	//trace_msg("num");

	push(atoi(node->text));
}

void run_svar(BT* node) {
	//trace_msg("svar");

	int offset = get_sym_offset(vt, node->data);
	push(load(offset));
}

void run_cvar(BT* node) {
	//trace_msg("cvar");

	rec_run_ast(node->children[0]);

	int offset = get_sym_offset(vt, node->data) + pop();
	store(offset, pop());
}

void run_plus(BT* node) {
	//trace_msg("plus");

	rec_run_ast(node->children[0]);
	rec_run_ast(node->children[1]);

	int r = pop();
	int l = pop();

	push(l + r);
}

void run_minus(BT* node) {
	//trace_msg("minus");

	rec_run_ast(node->children[0]);
	rec_run_ast(node->children[1]);

	int r = pop();
	int l = pop();
	
	push(l - r);
}

void run_times(BT* node) {
	//trace_msg("times");

	rec_run_ast(node->children[0]);
	rec_run_ast(node->children[1]);

	int r = pop();
	int l = pop();
	
	push(l * r);
}

void run_over(BT* node) {
	//trace_msg("over");

	rec_run_ast(node->children[0]);
	rec_run_ast(node->children[1]);

	int r = pop();
	int l = pop();
	
	push(l / r);
}

void run_lt(BT* node) {
	//trace_msg("lt");

	rec_run_ast(node->children[0]);
	rec_run_ast(node->children[1]);

	int r = pop();
	int l = pop();
	
	push(l < r);
}

void run_leq(BT* node) {
	//trace_msg("leq");

	rec_run_ast(node->children[0]);
	rec_run_ast(node->children[1]);

	int r = pop();
	int l = pop();
	
	push(l <= r);
}

void run_gt(BT* node) {
	//trace_msg("gt");

	rec_run_ast(node->children[0]);
	rec_run_ast(node->children[1]);

	int r = pop();
	int l = pop();
	
	push(l > r);
}

void run_geq(BT* node) {
	//trace_msg("geq");

	rec_run_ast(node->children[0]);
	rec_run_ast(node->children[1]);

	int r = pop();
	int l = pop();
	
	push(l >= r);
}

void run_eq(BT* node) {
	//trace_msg("eq");

	rec_run_ast(node->children[0]);
	rec_run_ast(node->children[1]);

	int r = pop();
	int l = pop();
	
	push(l == r);
}

void run_neq(BT* node) {
	//trace_msg("neq");

	rec_run_ast(node->children[0]);
	rec_run_ast(node->children[1]);

	int r = pop();
	int l = pop();
	
	push(l != r);
}

void run_if(BT* node) {
	//trace_msg("if");

	rec_run_ast(node->children[0]);
	int test = pop();

	if (test == 1) {
		rec_run_ast(node->children[1]);
	} else if (test == 0 && node->children_count == 3) {
		rec_run_ast(node->children[2]);
	}
}

void run_while(BT* node) {
	//trace_msg("while");

	rec_run_ast(node->children[0]); // Test
	int w = pop();

	while (w) {
		rec_run_ast(node->children[1]);
		rec_run_ast(node->children[0]); // Test
		w = pop();
	}
}

void run_fcall(BT* node) {}

void run_arg_list(BT* node) {}

void run_return(BT* node) {
	//implementar e testar o c11
}

void rec_run_ast(BT* node) {
	switch (node->kind) {
		case FUNC_DECL_LIST_NODE:
			run_func_decl_list(node);
		break;

		case FUNC_DECL_NODE:
			run_func_decl(node);
		break;

		case FUNC_HEADER_NODE:
			run_func_header(node);
		break;

		case PARAM_NODE:
			run_param_list(node);
		break;

		case FUNC_BODY_NODE:
			run_func_body(node);
		break;

		case VAR_LIST_NODE:
			run_var_list(node);
		break;

		case STMT_LIST_NODE:
			run_stmt_list(node);
		break;
		
		case INPUT_NODE:
			run_input(node);
		break;
		
		case OUTPUT_NODE:
			run_output(node);
		break;
		
		case WRITE_NODE:
			run_write(node);
		break;
		
		case ASSIGN_NODE:
			run_assign(node);
		break;
		
		case NUM_NODE:
			run_num(node);
		break;
		
		case SVAR_NODE:
			run_svar(node);
		break;
		
		case CVAR_NODE:
			run_cvar(node);
		break;
		
		case PLUS_NODE:
			run_plus(node);
		break;
		
		case MINUS_NODE:
			run_minus(node);
		break;
		
		case TIMES_NODE:
			run_times(node);
		break;
		
		case OVER_NODE:
			run_over(node);
		break;
		
		case LT_NODE:
			run_lt(node);
		break;
		
		case LEQ_NODE:
			run_leq(node);
		break;
		
		case GT_NODE:
			run_gt(node);
		break;
		
		case GEQ_NODE:
			run_geq(node);
		break;
		
		case EQ_NODE:
			run_eq(node);
		break;
		
		case NEQ_NODE:
			run_neq(node);
		break;
		
		case IF_NODE:
			run_if(node);
		break;
		
		case WHILE_NODE:
			run_while(node);
		break;
		
		case FCALL_NODE:
			run_fcall(node);
		break;
		
		case ARG_LIST_NODE:
			run_arg_list(node);
		break;

		case RETURN_NODE:
			run_return(node);
		break;
		
		default:
			fprintf(stderr, "Invalid kind: %s!\n", node2str(node));
			exit(1);
	}
}

void run_ast(BT* node) {
  init_stack();
  init_mem();
  rec_run_ast(node);
}