#ifndef BT_H
#define BT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define NUMCHILD 20

//numeral com tipos de nós possíveis na árvore de nó
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

//nó da árvore
//contem tipo do elemento (enum), vetor de tamanho fixo para filhos, contador para numero de filhos
//variavel contendo texto para caso de ID_NODE (nome da variavel ou da funcao)
struct node {
    NodeKind kind;
    int data;
    BT* children[NUMCHILD];
    int children_count;
    char* text;
};

//cria no da arvore
BT* create_node(NodeKind kind);

//cria apenas nos do tipo ID_NODE
BT* create_lit_node(NodeKind kind, int data, char* text);

//cria novo nó dado numero da linha
BT* new_leaf(NodeKind kind, int data);

//cria nó com numero variável de filhos (achei isso um máximo)
BT* new_node(NodeKind kind, int count, ...);

//adiciona UM filho ao nó
BT* add_child(BT* node, BT* child);

//imprime nó bonitinho
void print_node(BT *node, int level);
int print_node_dot(BT *tree);
void print_dot(BT *tree);

//imprime arvore
void print_tree(BT *tree);

//libera memória alocada para árvore
void free_tree(BT *tree);

//transforma enum em string para imprimir bonitinho
char* node2str(BT *node);

#endif
