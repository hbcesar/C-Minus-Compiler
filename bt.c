#include "bt.h"

BT* create_node(NodeKind kind) {
    BT* node = (BT*) malloc(sizeof(BT));
    node->kind = kind;
    node->children_count = 0;
    node->data = -1;

    return node;
}

BT* new_leaf(NodeKind kind, int data) {
    BT *leaf = create_node(kind);
    leaf->data = data;

    return leaf;
}

//https://en.wikipedia.org/wiki/Variadic_function#Variadic_functions_in_C.2C_Objective-C.2C_C.2B.2B.2C_and_D
BT* new_node(NodeKind kind, int count, ...) {
    int i;
    BT *node = create_node(kind);

    va_list ap;
    va_start(ap, count);

    for (i = 0; i < count; i++) {
        add_child(node, va_arg(ap, BT*));
    }

    va_end(ap);

    return node;
}

BT* add_child(BT* node, BT* child){
	if(node->children_count < NUMCHILD) {
		node->children[node->children_count] = child;
        node->children_count = node->children_count + 1;
	} else {
        printf("Excedeu o número de filhos de um nó, abortando!");
        exit(1);
    }

	return node;
}

void print_node(BT *node, int level) {
    int i;
    char* s = node2str(node);


    if (node->data == -1) {
        printf("%d: Node -- Addr: %p -- Text: %s -- Count: %d\n", level, node,
        s, node->children_count);
  
    } else {
        char d[64];
        sprintf(d, "%d", node->data);
        strcat(s, d);
        printf("%d: Node -- Addr: %p -- Text: %s -- Count: %d\n", level, node,
        s, node->children_count);
    }

    for (i = 0; i < node->children_count; i++) {
        print_node(node->children[i], level + 1);
    }
}

// void print_bt(BT *tree, int level) {
//     if (tree->l != NULL) print_bt(tree->l, level + 1);
//     print_node(tree, level);
//     if (tree->r != NULL) print_bt(tree->r, level + 1);
// }

void print_tree(BT *tree) {
    print_node(tree, 0);
}

void free_tree(BT *tree) {
    if (tree != NULL) {
        int i;
        for(i = 0; i < tree->children_count; i++){
            free_tree(tree->children[i]);
        }
        free(tree);
    }
}


// Dot output.
int nr;

int print_node_dot(BT *node) {
    int i;
    char* s = node2str(node);
    int my_nr = nr++;
    

    if(node->data != -1){
        sprintf(s, ",%d", node->data);
    }

    printf("node%d[label=\"%s\"];\n", my_nr, s);

    for (i = 0; i < node->children_count; i++) {
        int child_nr = print_node_dot(node->children[i]);
        printf("node%d -> node%d;\n", my_nr, child_nr);
    }

    return my_nr;
}

void print_dot(BT *tree) {
    nr = 0;
    printf("digraph {\ngraph [ordering=\"out\"];\n");
    print_node_dot(tree);
    printf("}\n");
}

// Dot output.
char* node2str(BT *node) {
    char* s = (char*)malloc(256*sizeof(char));

    switch(node->kind) {
        case NUMBER_NODE:               sprintf(s, "%s", "NUM"); break;
        case PLUS_NODE:                 sprintf(s, "%s", "+"); break;
        case MINUS_NODE:                sprintf(s, "%s", "-"); break;
        case TIMES_NODE:                sprintf(s, "%s", "*"); break;
        case OVER_NODE:                 sprintf(s, "%s", "/"); break;
        case FUNC_DECL_LIST_NODE:       sprintf(s, "%s", "func-decl-list"); break;
		case FUNC_DECL_NODE:			sprintf(s, "%s", "func-decl"); break;
		case FUNC_HEADER_NODE:		    sprintf(s, "%s", "func-header"); break;
		case FUNC_BODY_NODE:			sprintf(s, "%s", "func-body"); break;
		case VAR_LIST_NODE:				sprintf(s, "%s", "var-list"); break;
		case PARAM_NODE:				sprintf(s, "%s", "param"); break;
		case STMT_LIST_NODE:			sprintf(s, "%s", "stmt-list"); break;
		case ASSIGN_NODE:				sprintf(s, "%s", "="); break;
		case IF_NODE:					sprintf(s, "%s", "if"); break;
		case ELSE_NODE:					sprintf(s, "%s", "else"); break;
		case WHILE_NODE:				sprintf(s, "%s", "while"); break;
		case RETURN_NODE:				sprintf(s, "%s", "return"); break;
		case OUTPUT_NODE:				sprintf(s, "%s", "output"); break;
		case INPUT_NODE:				sprintf(s, "%s", "input"); break;
		case WRITE_NODE:				sprintf(s, "%s", "write"); break;
		case ARG_LIST_NODE:				sprintf(s, "%s", "arg-list"); break;
		case LT_NODE:					sprintf(s, "%s", "<"); break;
		case LEQ_NODE:					sprintf(s, "%s", "<="); break;
		case GT_NODE:					sprintf(s, "%s", ">"); break;
		case GEQ_NODE:					sprintf(s, "%s", ">="); break;
		case EQ_NODE:					sprintf(s, "%s", "=="); break;
		case NEQ_NODE:					sprintf(s, "%s", "!="); break;
		case ID_NODE:					sprintf(s, "%s", "id"); break;
		case NUM_NODE: 					sprintf(s, "%s", "num"); break;
		case STRING_NODE:				sprintf(s, "%s", "string"); break;
		case FCALL_NODE: 				sprintf(s, "%s", "func-call"); break;
		case SVAR_NODE:					sprintf(s, "%s", "svar"); break;
		case CVAR_NODE:					sprintf(s, "%s", "cvar"); break;
		case INT_NODE:					sprintf(s, "%s", "INT"); break;
		case VOID_NODE:					sprintf(s, "%s", "VOID"); break;
        default: 						sprintf(s, "%s", "ERRO"); break;
    }

    return s;
}
