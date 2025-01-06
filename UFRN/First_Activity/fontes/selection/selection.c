#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void selection_sort(int *v, unsigned int n);

void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}

void selection_sort(int *arr, unsigned int size)
{
    unsigned int i, j;
    int min_index;

    for (i = 0; i < (size - 1); i++)
    {
        min_index = i;
        for (j = (i + 1); j < size; j++)
        {
            // Verifying if the actual element is greater than the before
            if (arr[min_index] > arr[j])
                min_index = j;
        }
        // Changes the elements
        swap(&arr[min_index], &arr[i]);
    }
}

int main(int argc, char **argv)
{
    struct timespec a, b;
    unsigned int t, n;
    int i, *vetor;

    n = atoi(argv[1]);
    vetor = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < n; i++)
        vetor[i] = rand() % n;

    clock_gettime(CLOCK_MONOTONIC, &b);
    selection_sort(vetor, n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(vetor);

    return 0;
}
