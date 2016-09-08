/*
 * Tees.c

 *
 *  Created on: May 27, 2016
 *      Author: n
 */
#include<stdbool.h>
#include<stdio.h>
typedef void* element;
typedef struct node_t {
	//element data;
	int info;
	int key;
	struct node_t* left;
	struct node_t* right;
	struct node_t* father;
} *Node;

typedef struct tree_t {
	Node head;
	int size;
}* Tree;

/*
 * Travel on Trees :
 *Preorder :
 */
void preOrder(Node t){
	if(!t) return;
	printf("%d ", t->info);
	preOrder(t->left);
	preOrder(t->right);
	return;
}

void inOrder(Node t){
	if(!t) return;
	inOrder(t->left);
	printf("%d ", t->key);
	inOrder(t->right);
	return;
}

bool findKey(Node t, int key){
	if(!t) return 0;
	if(t->key > key){
		return findKey(t->left,key);
	}
	if(t->key < key){
		return findKey(t->right,key);
	}
	if(t->key == key) return 1;
	return 0;
}

void insert(Node t, Node* newNode){
	if(!t) return; // Assume this is illegal input
	if(t->key == (*newNode)->key) return;
	if(t->key > (*newNode)->key){
		if(!t->left){
			t->left = *newNode;
			return;
		}
		else{
			insert(t->left, newNode);
		}
	}
	if(t->key < (*newNode)->key){
		if(!t->right){
			t->right = *newNode;
			return;
		}
		else{
			insert(t->right, newNode);
		}
	}
}
/*
 * find the follower element in the tree given a node inside the tree.
 * time complexity : O(h)
 * memory complexity : O(h)
 */
Node findFollower(Node r){
	if(!r) return NULL;
	// Simple Case : r has right son:
	if(r->right != NULL){
		Node n = r->right;
		while(n->left != NULL){
			n = n->left;
		}
		return n;
	}
	// Case 2: doesn't have right son:
	// Go up until father is a left son:
	// root case:
	if(r->father == NULL) return NULL; // he is the largest.
	Node father = r->father;
	Node i = r;
	while(father->left != i){
		i = father;
		father = father->father;
	}
	return father;
}

int main(){
	printf("Start of tree functions\n");
	struct node_t r = {1, 27, NULL,NULL,NULL};
	struct node_t n1 = {1, 35, NULL,NULL,NULL};
	struct node_t n2 = {1, 15, NULL,NULL,NULL};
	struct node_t n3 = {1, 20, NULL,NULL,NULL};
	struct node_t n4 = {1, 5, NULL,NULL,NULL};
	struct node_t n5 = {1, 2, NULL,NULL,NULL};
	struct node_t n6 = {1, 10, NULL,NULL,NULL};
	struct node_t n7 = {1, 22, NULL,NULL,NULL};
	struct node_t n8 = {1, 21, NULL,NULL,NULL};
	struct node_t n9 = {1, 32, NULL,NULL,NULL};
	struct node_t n10 = {1, 45, NULL,NULL,NULL};
	struct node_t n11 = {1, 40, NULL,NULL,NULL};
	struct node_t n12 = {1, 50, NULL,NULL,NULL};

	Node np1 = &n1;
	Node np2 = &n2;
	Node np3 = &n3;
	Node np4 = &n4;
	Node np5 = &n5;
	Node np6 = &n6;
	Node np7 = &n7;
	Node np8 = &n8;
	Node np9 = &n9;
	Node np10 = &n10;
	Node np11 = &n11;
	Node np12 = &n12;


	insert(&r, &np1);
	insert(&r, &np2);
	insert(&r, &np3);
	insert(&r, &np4);
	insert(&r, &np5);
	insert(&r, &np6);
	insert(&r, &np7);
	insert(&r, &np8);
	insert(&r, &np9);
	insert(&r, &np10);
	insert(&r, &np11);
	insert(&r, &np12);
	inOrder(&r);
	Node nx =  findFollower(np7);
	printf("%d " ,nx->key);
	printf("End of tree functions\n");
	return 1;
}
