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
	if(literal_exists(lt, literal)){
		return get_literal_index(lt, literal);
	}

	LiteralNode* newNode = (LiteralNode*)malloc(sizeof(LiteralNode));

	newNode->literal = (char*) malloc(strlen(literal) * sizeof(char));
	strcpy(newNode->literal, literal);
	newNode->prox = NULL;

	if(lt->table == NULL) {
		lt->table = newNode;
		lt->fim = newNode;
	} else{
		lt->fim->prox = newNode;
		lt->fim = newNode;
	}

	return lt->count++;
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

	return -1;
}

char* get_literal(LiteralsTable* lt, int i){
	LiteralNode* llist = lt->table;
	int j;

	for(j = 0; j < i; j++){
		llist = llist->prox;
	}

	return llist->literal;
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
		free(temp->literal);
		lt->table = lt->table->prox;
		free(temp);
	}

	free(lt);
}