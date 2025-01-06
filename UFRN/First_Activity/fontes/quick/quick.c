#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *array, int start, int end);
int partition(int *array, int start, int end);
void swap(int *a, int *b);

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
    quick_sort(vetor, 0,n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}

void quick_sort(int *array, int start, int end)
{

    if (start < end)
    {
        int q = partition(array, start, end);
        // Recursives calls of the function
        quick_sort(array, start, q - 1);
        quick_sort(array, q + 1, end);
    }
}

int partition(int *array, int start, int end)
{
    unsigned int d = start-1;

    for (int i = start; i < (end-1); i++)
    {

        // Verifying if the element is smaller than pivot
        if (array[i] <= array[end])
        {
            d++;
            // Changes the elements
            swap(&array[d], &array[i]);
            // Increments the pivot
        }
    }

    // Changes pivot
    swap(&array[d+1], &array[end]);

    // Returns the pivot index
    return d+1;
}

void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}
