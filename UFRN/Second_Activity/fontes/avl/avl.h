#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tree_node {
    int value;
    struct tree_node *father;
    unsigned int height;
    struct tree_node *lchild;
    struct tree_node *rchild;
};

struct tree_node** search(struct tree_node** node, int value);
unsigned int height (struct tree_node* node);
struct tree_node* createNode(int value);
void insert(struct tree_node** aux, struct tree_node* node);
void balance(struct tree_node* node, struct tree_node** root);
void rotateLeft(struct tree_node** node);
void rotateRight(struct tree_node** node);
int diferenceHeight(struct tree_node* node);
void freeTree(struct tree_node* root);
// void verArvore(struct tree_node* raiz);
int whichCase(struct tree_node* node);