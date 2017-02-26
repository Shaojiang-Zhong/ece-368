#include "packing.h"
/*
void push(Stack s, Node *pointer);
Node *pop(Stack s);
int size(Stack s);
bool isFull(Stack s);
*/
int size(Stack *s){

	return (int)sizeof(s->stk)/sizeof((s->stk)[0]);

}
int isEmpty(Stack *s){

	if (s->top < 0) return 1;
	else return 0;

}

int isFull(Stack *s){
	if (size(s)==s->top+1) return 1;
	else return 0;




}
void push(Stack *s, Node *node){
	if (isFull(s)) printf("stack full!");
	else{
		s->top += 1;
		s->stk[s->top] = node;

	}

}

Node *pop(Stack *s){
	if(isEmpty(s)) return NULL;
	else{
		Node *tmp = s->stk[s->top];
		s->top -= 1;
		return tmp;
	}

}


void setValue(char *width,char *height, char *number, Node *node){
	float *tmp = (float*)malloc(sizeof(float));
	sscanf(width, "%e", tmp);
	node->wid = (long)*tmp;
	
	sscanf(height, "%e", tmp);
	node->hei = (long)*tmp;
	
	sscanf(number, "%e", tmp);
	node->num = (long)*tmp;
	
	free(tmp);

	return;
}

Node *createVH(char *array){

	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->dir = array[0];
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;


}
Node *createNum(char *array){
	


/*
const char *c = "the string";
  char *start = &c[4];
  char *end = &c[7];
  // Note the + 1 here, to have a null terminated substring
  char *substr = (char *)calloc(1, end - start + 1);
  memcpy(substr, start, end - start);

*/
	int pIndex = -1;	
	char width[20] = "";
	char height[20] = "";
	char number[20] = "";
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	pIndex = findIndex(array);
	
	if(pIndex == -1) return NULL;
	


//	memcpy(width, &array[2], &array[14]-&array[2]);
//	memcpy(height, &array[15], &array[27]-&array[15]);

	memcpy(width, &array[pIndex+1], 12);
	memcpy(height, &array[pIndex+14], 12);
	memcpy(number, &array[0], pIndex);

/*
	printf("wid:test %s\n", width);
	printf("hei:test %s\n", height);	
	printf("num:test %s\n", number);	
*/
	
	newNode->dir = 'X';

/*
	newNode->num = (long)array[0];
	sscanf(width, "%ld", &(newNode->wid));
	sscanf(height, "%ld", &(newNode->hei));
	memcpy(&(newNode->wid), width, sizeof(long));
	memcpy(&(newNode->hei), height, sizeof(long));
	printf("wid num %ld\n", newNode->wid);
	printf("hei num %ld\n", newNode->hei);
*/

	setValue(width, height, number, newNode);

	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;


}

int findIndex(char *array){
	int i;
	//printf("%ld\n", sizeof(*array));
	for(i=0; i < strlen(array) ; i++){
		//printf("%c\n", array[i]);
		if(array[i] == '(') return i;
		//printf("%c", array[i]);

	}
	printf("error get out");
	return -1;


}

Node *load_binary_tree_from_file(char* Filename){


	FILE * fptr = fopen(Filename, "r");
	char lineArray[40];
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->top = -1;




	Node *root = NULL;
	Node *nodeR = NULL;
	Node *nodeL = NULL;




	while (fgets(lineArray, sizeof(lineArray), fptr)){

		//printf("%s", lineArray);

		if(lineArray[0] < '9' && lineArray[0] > '0') {
			push(stack, createNum(lineArray));
		}
		
		else if (lineArray[0] == 'V' || lineArray[0] == 'H'){
			nodeR = pop(stack);
			nodeL = pop(stack);
			if(nodeR == NULL || nodeL == NULL){
				free(stack);
				fclose(fptr);
				printf("stack error");
				return NULL;
			}else{
				Node *VH = createVH(lineArray);
				VH->left = nodeL;
				VH->right = nodeR;
				push(stack, VH);

			}

		}
		else{
			continue;

		}




	}
	root = pop(stack);
	free(stack);
	fclose(fptr);

	return root;

}

void printNode(Node* node){

	if (node == NULL) printf("ERROR: EMPTY NODE");
	else{
		if(node->dir == 'X'){
		printf("\nnum: %ld\n", node->num);
		printf("wid: %ld\n", node->wid);
		printf("hei: %ld\n", node->hei);
		printf("dir: %c\n", node->dir);
		}
		else if (node->dir == 'V' || node->dir == 'H'){
		printf("\ndir: %c\n", node->dir);

		}
		else{printf("ERROR no dir ");
}


	}


}


void printTree(Node *root){
	if(root == NULL) return;
	printNode(root);
	printTree(root->left);
	printTree(root->right);

}










