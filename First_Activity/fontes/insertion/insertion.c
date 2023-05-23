#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

void insertionSort(int *arr, int n)
{
    unsigned int i, j;
    for (i = 1; i < n; i++)
    {
        j = i;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(&arr[j - 1], &arr[j]);
            j = j - 1;
        }
    }
}

int main(int argc, char **argv)
{
    struct timespec a, b;
    unsigned int t, n;
    int i, *v;

    n = atoi(argv[1]);
    v = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < n; i++)
        v[i] = rand() % n;

    clock_gettime(CLOCK_MONOTONIC, &b);
    insertionSort(v, n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
}

void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}
