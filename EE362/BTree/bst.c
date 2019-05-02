/*
 * Program that build a binary search tree of 10 nodes:
 *    55, 34, 71, 15, 47, 6, 39, 99, 80, 100
 * Then deletes node 71, and then node 34.
 * The program displays the current tree, then the two trees after
 * each deletion.
 *
 * The function 'delete_node(root, value) is supposed to delete
 * a node with value 'value' in the tree 'root'.  But it doesn't work.
 * Your are to implement 'delete_node' so that it works properly.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node * left;
	struct node * right;
};

struct node * insert_node(struct node * root, struct node * new);
struct node * delete_node(struct node * root, int value);
struct node * create_node(int value);
void display(struct node * root);
void display(struct node * root);


void main() 
{
struct node * root = NULL;
struct node * new;

new = create_node(55);
root = insert_node(root, new);
new = create_node(34);
root = insert_node(root, new);
new = create_node(71);
root = insert_node(root, new);
new = create_node(15);
root = insert_node(root, new);
new = create_node(47);
root = insert_node(root, new);
new = create_node(6);
root = insert_node(root, new);
new = create_node(39);
root = insert_node(root, new);
new = create_node(99);
root = insert_node(root, new);
new = create_node(80);
root = insert_node(root, new);
new = create_node(100);
root = insert_node(root, new);

printf("Initial tree:\n");
display(root);

printf("\nTree after deleting value 71:\n");
root = delete_node(root, 71);
display(root);

printf("\nTree after deleting value 34:\n");
root = delete_node(root, 34);
display(root);
}

/* 
 * The follwing function doesn't work.  Make changes to this
 * function so that it works properly
 */
struct node * delete_node(struct node * root, int value)
{
	return root;
}

struct node * insert_node(struct node * root, struct node * new)
{
if (root==NULL) return new;
if (new->value < root->value) { 
	root->left = insert_node(root->left, new);
}
if (new->value > root->value) { 
	root->right = insert_node(root->right, new);
}
return root;
}


struct node * create_node(int value)
{
struct node * p = (struct node *) malloc(sizeof(struct node *));
p->value = value;
p->left = NULL;
p->right = NULL;
return p;
}


void display(struct node * root)
{
if (root==NULL) return;

printf("Node %d: ", root->value);
if (root->left!=NULL) {
	printf(" %d ,", root->left->value);
}
else {
	printf(" NULL ,");
}
if (root->right!=NULL) {
	printf(" %d \n", root->right->value);
}
else {
	printf(" NULL \n");
}
display(root->left);
display(root->right);
}




