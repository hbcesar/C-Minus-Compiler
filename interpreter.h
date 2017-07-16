#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "bt.h"

void run_ast(BT*);

void push(int);

int pop();

void init_stack();

void print_stack();


// ------------------------- MEMÓRIA ----------------------------------

void store(int, int);

int load(int);

void init_mem();


// ------------------------- FUNÇÕES ----------------------------------

void trace_msg(char*);

void rec_run_ast(BT*);

void run_func_decl_list(BT*);

void run_func_decl(BT*);

void run_func_header(BT*);

void run_param_list(BT*);

void run_func_body(BT*);

void run_var_list(BT*);

void run_stmt_list(BT*);

void run_input(BT*);

void run_output(BT*);

void run_write(BT*);

void run_assign(BT*);

void run_num(BT*);

void run_svar(BT*);

void run_cvar(BT*);

void run_plus(BT*);

void run_minus(BT*);

void run_times(BT*);

void run_over(BT*);

void run_lt(BT*);

void run_leq(BT*);

void run_gt(BT*);

void run_geq(BT*);

void run_eq(BT*);

void run_neq(BT*);

void run_if(BT*);

void run_while(BT*);

void run_fcall(BT*);

void run_arg_list(BT*);

void rec_run_ast(BT*);

void run_ast(BT*);

#endif