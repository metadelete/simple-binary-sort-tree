#include <stdlib.h>
#include <time.h>
#include <stdio.h>
typedef struct TREE_NODE {
  struct TREE_NODE* right;
  struct TREE_NODE* left;
  struct TREE_NODE* parent;//parent is not used for any node in a tree. it might be useful in some cases, but not in this program.
  int value;
} TREE_NODE;

int MAX_NODE = 100;
TREE_NODE *parent = NULL;
TREE_NODE *crawler = NULL;
TREE_NODE *trail = NULL;
int kontrol = 0;

void insert_node(TREE_NODE **node, int);
void list_values(TREE_NODE *node);
static int _rand(){return rand()%1000 + 1;}
int main()
{
	srand(time(NULL));

	int *array;
	array = (int*)malloc(sizeof(int) * MAX_NODE);

  	TREE_NODE* node = NULL;
  	int counter = 0;

  	while(counter < MAX_NODE) {
  		array[counter] = _rand();
  		printf("%d\n", array[counter]);
  		counter++;
  	}
	printf("\n\n\n");


	// Binary Tree Process Begin
  	counter = 0;
  	while(counter < MAX_NODE) {
  		node = (TREE_NODE*)malloc(sizeof(TREE_NODE));
  		insert_node(&node ,array[counter]);
  		crawler = trail = parent;
  		counter++;
  	}
  	// Binary Tree Process End


  	crawler = parent;
  	printf("%s\n","Begin process of listing");
  	list_values(NULL);
  	printf("%s\n","End process of listing");


  	printf("%s\n", "the end");
}
void insert_node(TREE_NODE **node, int value)
{
	if(parent == NULL) {
		TREE_NODE *child = (TREE_NODE*)malloc(sizeof(TREE_NODE));
		child->value = value;
		child->left = NULL;
		child->right = NULL;
		parent = child;
		return;
	} else {
		if(crawler == NULL) {
			TREE_NODE *child = (TREE_NODE*)malloc(sizeof(TREE_NODE));
			child->value = value;
			child->left = NULL;
			child->right = NULL;
			*node = child;
			switch(kontrol){case 0:trail->left = crawler;break;case 1:trail->right = crawler;break;}
			return;
		} else {
			if(value <= crawler->value) {
				trail = crawler;
				crawler = crawler->left;
				kontrol = 0;
				insert_node(&(crawler), value);
			} else {
				trail = crawler;
				crawler = crawler->right;
				kontrol = 1;
				insert_node(&(crawler), value);
			}
		}		
	}
}
void list_values(TREE_NODE *node)
{
	if(node == NULL) {
		if(parent->left != NULL) {
			list_values(parent->left);
			printf("%d\n", parent->value);
			if(parent->right != NULL ) {
				list_values(parent->right);
			}
		} else {
			printf("$d\n", parent->value);
			if(parent->right != NULL) {
				list_values(parent->right);
			}
		}
		return;
	}
	if(node->left != NULL) {
		list_values(node->left);
		printf("%d\n", node->value);
		if(node->right != NULL) {
			list_values(node->right);
		}
	} else {
		printf("%d\n", node->value);
		if(node->right != NULL) {
			list_values(node->right);

		}
	}
}
