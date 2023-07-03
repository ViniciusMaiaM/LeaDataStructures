#include "binary_tree.h"


struct tree_node *tree_new(int value)
{
    struct tree_node *new_node;

    new_node = (struct tree_node *) malloc(sizeof(struct tree_node));
    new_node->value = value;
    new_node->lchild = NULL;
    new_node->rchild = NULL;

    return new_node;
}

struct tree_node **tree_search(struct tree_node** root, int value)
{
    if((*root) != NULL){
        if((*root)->value == value){
            return root;
        }
        
        else if (value < (*root)->value) {
            return tree_search(&((*root)->lchild), value);
        
        }
        return tree_search(&((*root)->rchild), value);
    }

    return NULL;
}

void tree_insert(struct tree_node **root, struct tree_node *w)
{
    if ((*root) == NULL)
    {   
        (*root) = w;
    }

    else
    {
        if ((*root)->value < w->value){
            tree_insert(&((*root)->rchild), w);
        }

        else{
            tree_insert(&((*root)->lchild), w);
        }
    }
}

int main(int argc, char **argv) {
    struct timespec a, b;
    unsigned int t, n;
    int i;
    struct tree_node *root = NULL;
    int last = 0;

    n = atoi(argv[1]);
    srand(time(NULL));
    for (i = 0; i < n; i++){
        last = rand();
        tree_insert(&root, tree_new(last));
    }

    clock_gettime(CLOCK_MONOTONIC, &b);
    tree_search(&root, last+1);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    return 0;
}