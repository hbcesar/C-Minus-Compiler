#include "literalsTable.h"

LiteralsTable* create_lit_table(void){
	LiteralsTable *lt = (LiteralsTable*)malloc(sizeof(LiteralsTable));
	lt->table = NULL;
	lt->fim = NULL;
	lt->count = 0;

	return lt;
}

int literal_exists(LiteralsTable* lt, char* literal){
	LiteralNode* llist = lt->table;

	int i = 0;
	while (llist != NULL) {
		if (strcmp(llist->literal, literal) == 0) {
			return i;
		}

		llist = llist->prox;
		i++;
	}

	return 0;
}

int add_literal(LiteralsTable* lt, char* literal){
	if(literalExists(lt, literal)){
		return -1;
	}

	LiteralNode* newNode = (LiteralNode*)malloc(sizeof(LiteralNode));
	strcpy(newNode->literal, literal);
	newNode->next = NULL;

	if(lt->table == NULL) {
		lt->table = newNode;
		lt->fim = newNode;
	} else{
		lt->fim->prox = newNode;
		lt->fim = newNode;
	}

	lt->count++;

	return 0;
}

int get_literal_index(LiteralsTable* lt, char* literal){
	LiteralNode* llist = lt->table;
	int i = 0;

	while (llist != NULL) {
		if (strcmp(llist->literal, literal) == 0) {
			return i;
		}

		llist = llist->prox;
		i++;
	}
	return 0;
}

char* get_literal(LiteralsTable lt, int i){
	LiteralNode* llist = lt->table;
	int j;

	for(j = 0; j < i; j++){
		llist = llist->prox;
	}

	return llist;
}

void print_literals_table(LiteralsTable* lt){
	printf("\nLiterals table:");
	LiteralNode* llist = lt->table;

	int i = 0;
	while (llist != NULL) {
		printf("\nEntry %d -- %s", i, llist->literal);
		llist = llist->prox;
		i++;
	}

	printf("\n\n");
}

void free_literals_table(LiteralsTable* lt){
	LiteralNode* temp;

	while (lt->table != NULL) {
		temp = lt->table;
		lt->table = lt->table->prox;
		free(temp);
	}
}