#ifndef SYMBOLSTABLE_H
#define SYMBOLSTABLE_H

#include "bt.h"
#define MAX_SYMBOL 256

typedef struct symNode {
	char symbol[MAX_SYMBOL];
	int line;
	int escopo;
	int aridade;
	struct symNode* prox;
} SymbolNode;

typedef struct symTable {
	SymbolNode* table;
	SymbolNode* fim;
	int count;
} SymbolsTable;

SymbolsTable* create_sym_table(void);
int lookup_var(SymbolsTable* st, char* symbol);
char* get_name(SymbolsTable* st, int i);
int add_var(SymbolsTable* st, char* symbol, int line, int escopo, int aridade);
int get_line(SymbolsTable* st, char* symbol);
int get_symbol_escope(SymbolsTable* st, char* symbol);
int get_symbol_arity(SymbolsTable* st, char* symbol);
int get_symbol_index(SymbolsTable* st, char* symbol, int escopo);
void print_variables_table(SymbolsTable* st);
void print_functions_table(SymbolsTable* st);
void free_sym_table(SymbolsTable* st);

#endif