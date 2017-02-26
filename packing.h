#ifndef SORTING_H
#define SORTING_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct _Node {


	long num;
	long wid;
	long hei;
	long x;
	long y;
	char dir;

	struct _Node *left;
	struct _Node *right;
} Node;

typedef struct _Stack {
	Node* stk[20];
	int top;

} Stack;



Node *load_binary_tree_from_file(char* Filename);

void perform_packing(Node* root);

long save_packing_to_file(Node* root);
Node *createVH(char *array);
Node *createNum(char *array);
void printNode(Node* node);
int findIndex(char *array);


void push(Stack *s, Node *node);
Node *pop(Stack *s);
int size(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void printTree(Node *root);
#endif
