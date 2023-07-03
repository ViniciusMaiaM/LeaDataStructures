#include "avl.h"

struct tree_node** search(struct tree_node** root, int value){
    if ((*root) != NULL) {
        if((*root)->value == value){
            return root;
        }
        else if ((*root)->value > value){
            return search(&((*root)->lchild), value);
        }

        return search(&((*root)->rchild), value);
    }
    return NULL;
}

unsigned int height(struct tree_node* node) {
    if (node == NULL) {
        return 0;
    }
    if ((node->rchild != NULL) && (node->lchild != NULL)) {
        if ((node->rchild->height) > (node->lchild->height)) {
            return (node->rchild->height) + 1;
        }

        return (node->lchild->height) + 1;
    }

    else if ((node->lchild == NULL) && ((node->rchild != NULL))) {
        return node->rchild->height + 1;
    }

    else if ((node->lchild != NULL) && ((node->rchild == NULL))) {
        return node->lchild->height + 1;
    }

    return 1;
}

struct tree_node* createNode(int value) {
    struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
    node->value = value;
    node->father = NULL;
    node->height = 1;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

void insert(struct tree_node** aux, struct tree_node* node) {
    if (*aux == NULL) {
        *aux = node;
        balance(*aux, aux);
    }
    else {
        node->father = *aux;
        if ((*aux)->value > node->value) {
            insert(&((*aux)->lchild), node);
        }
        else {
            insert(&((*aux)->rchild), node);
        }
    }
}

int differenceHeight(struct tree_node* node) {
    if ((node->lchild != NULL) && (node->rchild != NULL)) {
        return abs(node->lchild->height - node->rchild->height);
    } 

    else if ((node->lchild == NULL) && (node->rchild != NULL)) {
        return node->rchild->height;
    } 

    else if ((node->lchild != NULL) && (node->rchild == NULL)) {
        return node->lchild->height;
    }

    return 0;
}


int whichCase(struct tree_node* node) {
    if ((node != NULL) && (node->lchild != NULL) && (node->rchild != NULL)) {

        if ((node->lchild->height) > (node->rchild->height)) {

            if ((node->lchild->lchild != NULL) && (node->lchild->rchild != NULL)) {
                
                if ((node->lchild->lchild->height) > (node->lchild->rchild->height)) {
                    return 1;
                } 
                
                else {
                    return 3;
                }
            }
        } 
        
        else {
            if ((node->rchild->rchild != NULL) && (node->rchild->lchild != NULL)) {
                if ((node->rchild->rchild->height) > (node->rchild->lchild->height)) {
                    return 2;
                } 
                
                else {
                    return 4;
                }
            }
        }
    }

    else if ((node->lchild != NULL) && (node->rchild == NULL)){
        if ((node->lchild->lchild != NULL) && (node->lchild->rchild == NULL)) {
            return 1;
        }

        else {
            return 3;
        }
    }

    else {
        if ((node->rchild->lchild == NULL) && (node->rchild->rchild != NULL)) {
            return 2;
        }
    }
    

    return 4;
}


void balance(struct tree_node* node, struct tree_node** root) {
    node = node->father;

    while (node != NULL) {
        node->height = height(node);

        if (differenceHeight(node) > 1) {
            whichCase(node);

            if (whichCase(node) == 1) {
                rotateRight(&node);
            } 

            else if (whichCase(node) == 2) {
                rotateLeft(&node);
            } 

            else if (whichCase(node) == 3) {
                rotateLeft(&(node->lchild));
                rotateRight(&node);
            } 

            else {
                rotateRight(&(node->rchild));
                rotateLeft(&node);
            }

        }

        node = node->father;
    }
}

void rotateLeft(struct tree_node** node) {
    struct tree_node* x = *node;
    struct tree_node* y = x->rchild;
    struct tree_node* b = y->lchild;

    x->rchild = b;

    if (b != NULL) {
        b->father = x;
    }

    y->lchild = x;
    y->father = x->father;
    x->father = y;
    x->height = height(x);
    y->height = height(y);

    if (y->father != NULL) {
        if (y->father->value > y->value) {
            y->father->lchild = y;
        }
        else {
            y->father->rchild = y;
        }
    }

    *node = y;
}

void rotateRight(struct tree_node** node) {
    struct tree_node* x = *node;
    struct tree_node* y = x->lchild;
    struct tree_node* b = y->rchild;

    x->lchild = b;

    if (b != NULL) {
        b->father = x;
    }

    y->rchild = x;
    y->father = x->father;
    x->father = y;
    x->height = height(x);
    y->height = height(y);

    if (y->father != NULL) {
        if (y->father->value > y->value) {
            y->father->lchild = y;
        }
        else {
            y->father->rchild = y;
        }
    }
    
    *node = y;
}

void freeTree(struct tree_node* root) {
    if (root != NULL) {
        freeTree(root->lchild);
        freeTree(root->rchild);
        free(root);
    }
}


int main(int argc, char **argv){
    struct tree_node* root = NULL;

    struct timespec a, b;
    unsigned int t, n;
    int i;

    n = atoi(argv[1]);
    srand(time(NULL));
    for (i = 0; i < n; i++)
        insert(&root, createNode(rand()));

    clock_gettime(CLOCK_MONOTONIC, &b);
    search(&root, rand());
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    freeTree(root);
    
    return 0;
}