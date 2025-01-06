#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

// Based on João Paulo algorithms
struct tree_node
{
    int value;
    struct tree_node *lchild;
    struct tree_node *rchild;
};

struct tree_node *tree_new(int v); 

void tree_insert(struct tree_node **r, struct tree_node *w);

struct tree_node** tree_search(struct tree_node** root, int value);