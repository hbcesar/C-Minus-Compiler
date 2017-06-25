#ifndef SYMBOLSTABLE_H
#define SYMBOLSTABLE_H

#include "bt.h"

//no simbolo, contem texto com nome do simbolo,
//linha na qual ele foi declarada, escopo e aridade
typedef struct symNode {
	char* symbol;
	int line;
	int escopo;
	int aridade;
	struct symNode* prox;
} SymbolNode;

//estrutura para tabela de simbolos
typedef struct symTable {
	SymbolNode* table;
	SymbolNode* fim;
	int count;
} SymbolsTable;

//aloca espaco para estrutura de tabela de simbolo
SymbolsTable* create_sym_table(void);

//adiciona simbolo a tabela
int add_var(SymbolsTable* st, char* symbol, int line, int escopo, int aridade);

//verifica se simbolo existe na tabela (retorna 1 se true e 0 se false)
int lookup_var(SymbolsTable* st, char* symbol);

//retorna linha na qual o simbolo foi declarado no código
int get_line(SymbolsTable* st, char* symbol);

//retorna escopo do simbolo
int get_symbol_escope(SymbolsTable* st, char* symbol);

//retorna ariadade do simbolo
int get_symbol_arity(SymbolsTable* st, char* symbol);

//retorna index do simbolo na tabela
int get_symbol_index(SymbolsTable* st, char* symbol, int escopo);

//imprime tabela de simbolos
void print_variables_table(SymbolsTable* st);
void print_functions_table(SymbolsTable* st);

//desaloca espaco de memoria para tabela de simbolos
void free_sym_table(SymbolsTable* st);

#endif