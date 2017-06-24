#ifndef BT_H
#define BT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> //Retirado de: https://en.wikipedia.org/wiki/Variadic_function#Variadic_functions_in_C.2C_Objective-C.2C_C.2B.2B.2C_and_D
#include <string.h>

#define NUMCHILD 50

typedef enum {
	NUMBER_NODE,
	PLUS_NODE,
	MINUS_NODE,
	TIMES_NODE,
	OVER_NODE,
	FUNC_DECL_LIST_NODE,
	FUNC_DECL_NODE,
	FUNC_HEADER_NODE,
	FUNC_BODY_NODE,
	VAR_LIST_NODE,
	PARAM_NODE,
	STMT_LIST_NODE,
	ASSIGN_NODE,
	IF_NODE,
	ELSE_NODE,
	WHILE_NODE,
	RETURN_NODE,
	OUTPUT_NODE,
	INPUT_NODE,
	WRITE_NODE,
	ARG_LIST_NODE,
	LT_NODE,
	LEQ_NODE,
	GT_NODE,
	GEQ_NODE,
	EQ_NODE,
	NEQ_NODE,
	ID_NODE,
	NUM_NODE,
	STRING_NODE,
	FCALL_NODE,
	SVAR_NODE,
	CVAR_NODE,
	INT_NODE,
	VOID_NODE,
} NodeKind;

typedef struct node BT;

struct node {
    NodeKind kind;
    int data;
    BT* children[NUMCHILD];
    int children_count;
};

BT* create_node(NodeKind kind);
BT* new_leaf(NodeKind kind, int data);
BT* new_node(NodeKind kind, int count, ...);
BT* add_child(BT* node, BT* child);

void print_node(BT *node, int level);
void print_tree(BT *tree);
void free_tree(BT *tree);

int print_node_dot(BT *tree);
void print_dot(BT *tree);

char* node2str(BT *node);

#endif
