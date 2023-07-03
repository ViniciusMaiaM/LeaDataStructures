#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


struct list_node {
    int value;
    struct list_node* next;
};

struct hash_table {
    struct list_node** table;
    unsigned int size;
    unsigned int n;
};

struct hash_table* createHashTable();
int hashFunction(int key, int size);
void rehash(struct hash_table* hashTable);
void insert(struct hash_table* hashTable, int value);
int search(struct hash_table* hashTable, int key);
// void printHashTable(struct hash_table* hashTable);