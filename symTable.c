
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symbolsTable.h"

SymbolsTable* create_sym_table(void){
	SymbolsTable *st = (SymbolsTable*)malloc(sizeof(SymbolsTable));
	st->table = NULL;
	st->count = 0;

	return st;
}

int lookup_var(SymbolsTable* st, char* symbol){
	SymbolNode* slist = st->table;

	while (slist != NULL) {
		if (strcmp(slist->symbol, symbol) == 0) {
			return 1;
		}

		slist = slist->prox;
	}

	return 0;
}

char* get_name(SymbolsTable* st, int i){
	SymbolNode* slist = st->table;
	int j;

	for(j = 0; j < i; j++){
		slist = slist->prox;
	}

	return slist->symbol;
}

int add_var(SymbolsTable* st, char* symbol, int line, int escopo, int aridade){

	SymbolNode* node = (SymbolNode*) malloc(sizeof(SymbolNode));

	strcpy(node->symbol, symbol);
	node->line = line;

	if(escopo != -1){
		node->escopo = escopo;
	}

	if(aridade != -1){
		node->aridade = aridade;
	}

	node->prox = NULL;

	if(st->table == NULL) {
		st->table = node;
		st->fim = node;
	} else{
		st->fim->prox = node;
		st->fim = node;
	}

	st->count++;

	return 0;
}

int get_line(SymbolsTable* st, char* symbol){
	SymbolNode* slist = st->table;

	while (slist != NULL) {
		if(strcmp(slist->symbol, symbol) == 0) {
			return slist->line;
		}

		slist = slist->prox;
	}

	return -1;
}


int get_symbol_escope(SymbolsTable* st, char* symbol){
	SymbolNode* slist = st->table;

	while (slist != NULL) {
		if(strcmp(slist->symbol, symbol) == 0) {
			return slist->escopo;
		}

		slist = slist->prox;
	}
	return -1;
}


int get_symbol_arity(SymbolsTable* st, char* symbol){
	SymbolNode* slist = st->table;

	while (slist != NULL) {
		if(strcmp(slist->symbol, symbol) == 0) {
			return slist->aridade;
		}

		slist = slist->prox;
	}
	return -1;
}

int get_symbol_index(SymbolsTable* st, char* symbol, int escopo){
	SymbolNode* slist = st->table;

	int i = 0;
	while (slist != NULL) {
		if(escopo == -1) {
			if (strcmp(slist->symbol, symbol) == 0) {
				return i;
			}

		} else if ((strcmp(slist->symbol, symbol) == 0) && (slist->escopo == escopo)) {
			return i;
		}
	

		slist = slist->prox;
		i++;
	}

	return 0;
}

void print_variables_table(SymbolsTable* st){
	printf("\nVariables table:");

	SymbolNode* slist = st->table;

	int i = 0;
	while (slist != NULL) {
		printf("\nEntry %d -- name: %s, line: %d, scope: %d", i, slist->symbol, slist->line, slist->escopo);
		slist = slist->prox;
		i++;
	}

	printf("\n\n");
	return;
}

void print_functions_table(SymbolsTable* st){
	printf("\nFunctions table:");

	SymbolNode* slist = st->table;

	int i = 0;
	while (slist != NULL) {
		printf("\nEntry %d -- name: %s, line: %d, arity: %d", i, slist->symbol, slist->line, slist->aridade);
		slist = slist->prox;
		i++;
	}

	printf("\n");
	return;
}

void free_sym_table(SymbolsTable* st){
	SymbolNode* temp;

	while (st->table != NULL)
	{
		temp = st->table;
		st->table = st->table->prox;
		free(temp);
	}
	return;
}