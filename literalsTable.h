#ifndef LITERALSTABLE_H
#define LITERALSTABLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bt.h"
#define MAX_LITERAL 256

typedef struct litNode {
    char literal[MAX_LITERAL];
    struct litNode* prox;
} LiteralNode;

typedef struct litTable {
    LiteralNode* table;
    LiteralNode* fim;
    int count;
} LiteralsTable;

LiteralsTable* create_lit_table(void);
int literal_exists(LiteralsTable* lt, char* literal);
int add_literal(LiteralsTable* lt, char* literal);
int get_literal_index(LiteralsTable* lt, char* literal);
char* get_literal(LiteralsTable* lt, int i);
void print_literals_table(LiteralsTable* lt);
void free_literals_table(LiteralsTable* lt);

#endif