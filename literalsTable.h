#ifndef LITERALSTABLE_H
#define LITERALSTABLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bt.h"

//nó de tabela de literais
typedef struct litNode {
    char* literal;
    struct litNode* prox;
} LiteralNode;

//estrutura para tabela de literais
typedef struct litTable {
    LiteralNode* table;
    LiteralNode* fim;
    int count;
} LiteralsTable;

//aloca espaço para tabela de literais
LiteralsTable* create_lit_table(void);

//adiciona um literal a tabela
int add_literal(LiteralsTable* lt, char* literal);

//verifica se um literal existe na tabela
int literal_exists(LiteralsTable* lt, char* literal);

//obtem posicao do literal NA TABELA
int get_literal_index(LiteralsTable* lt, char* literal);

//obtem literal dada sua posicao NA TABELA
char* get_literal(LiteralsTable* lt, int i);

//imprime a tabela de literais
void print_literals_table(LiteralsTable* lt);

//desaloca tabela de literais da memoria
void free_literals_table(LiteralsTable* lt);

#endif