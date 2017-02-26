#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "packing.h"



int main(int argc, char *argv[]){
	
	Node *root = NULL;
	root = load_binary_tree_from_file(argv[1]);
	printTree(root);
	




















	return 0;
}


/*
 
	//load_binary_tree_from_file(argv[1]);
	Node *test1;
	Node *test2;
	test1 = createNum("22345234(1.036840e+11,3.087940e+11)");
	
	test2 = createVH('V');
	printNode(test1);
	printNode(test2);

	


	Node *test = (Node*)malloc(sizeof(Node));
	
	//long *b = NULL;
	float *a = (float*)malloc(sizeof(float));
	sscanf("1.036840e+11", "%e", a);
	printf("%f\n", *a);
	test->wid = (long)(*a);
	printf("%ld\n", test->wid);


*/

