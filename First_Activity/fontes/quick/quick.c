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
        vetor[i] = rand();

    clock_gettime(CLOCK_MONOTONIC, &b);
    quick_sort(vetor, 0,n-1);
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
    int pivot = array[end]; // Pivot is the last element
    int index = start;
    unsigned int i;

    for (i = start; i < end; i++)
    {

        // Verifying if the element is smaller than pivot
        if (array[i] <= pivot)
        {
            // Changes the elements
            swap(&array[i], &array[index]);
            // Increments the pivot
            index++;
        }
    }

    // Changes pivot
    swap(&array[index], &array[end]);

    // Returns the pivot index
    return index;
}

void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}
