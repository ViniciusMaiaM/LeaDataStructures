#include "hash.h"

struct hash_table* createHashTable() {
    struct hash_table* hashTable = (struct hash_table*)malloc(sizeof(struct hash_table));

    hashTable->size = 1;
    hashTable->table = (struct list_node**)malloc(sizeof(struct list_node*) * hashTable->size);

    for (int i = 0; i < hashTable->size; i++) {
        hashTable->table[i] = NULL;
    }

    return hashTable;
}

int hashFunction(int key, int size) {
    return key % size;
}

void rehash(struct hash_table* hashTable) {
    int newSize = hashTable->size * 2;
    struct list_node** oldTable = hashTable->table;

    hashTable->size = newSize;
    hashTable->table = (struct list_node**)malloc(sizeof(struct list_node*) * newSize);

    for (int i = 0; i < newSize; i++) {
        hashTable->table[i] = NULL;
    }

    for (int i = 0; i < hashTable->size / 2; i++) {
        struct list_node* item = oldTable[i];
        while (item != NULL) {
            struct list_node* next = item->next;
            int index = hashFunction(item->value, hashTable->size);
            item->next = hashTable->table[index];
            hashTable->table[index] = item;
            item = next;
        }
    }

    free(oldTable);
}

void insert(struct hash_table* hashTable, int value) {
    int index = hashFunction(value, hashTable->size);

    if (hashTable->size == hashTable->n) {
        rehash(hashTable);
        index = hashFunction(value, hashTable->size);
    }

    struct list_node* newNode = (struct list_node*)malloc(sizeof(struct list_node));
    newNode->value = value;
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
    hashTable->n++;
}

int search(struct hash_table* hashTable, int key) {
    int index = hashFunction(key, hashTable->size);

    struct list_node* item = hashTable->table[index];
    while (item != NULL) {
        if (item->value == key) {
            return 1;
        }
        item = item->next;
    }

    return 0;
}

void printHashTable(struct hash_table* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        printf("Bucket %d: ", i);

        struct list_node* item = hashTable->table[i];
        while (item != NULL) {
            printf("%d -> ", item->value);
            item = item->next;
        }

        printf("NULL\n");
    }
}

int main(int argc, char **argv) {
    struct hash_table* hashTable = createHashTable();

    struct timespec a, b;
    unsigned int t, n;
    int i;

    n = atoi(argv[1]);
    srand(time(NULL));
    for (i = 0; i < n; i++)
        insert(hashTable,rand());

    clock_gettime(CLOCK_MONOTONIC, &b);
    search(hashTable, rand());
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(hashTable);

    return 0;
}
