#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int s, int m, int e)
{

	unsigned int p = s;
	unsigned int q = m + 1;
	int *w = (int *)malloc((e - s + 1) * sizeof(int));

	for (int i = 0; i < (e - s + 1); i++)
	{
		if ((q > e) || ((p <= m) && (arr[p] < arr[q])))
		{
			w[i] = arr[p];
			p++;
		}
		else
		{
			w[i] = arr[q];
			q++;
		}
	}

	for (int j = 0; j < (e - s + 1); j++)
	{
		arr[s + j] = w[j];
	}
	free(w);
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{

		int m = (l + r) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
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
	mergeSort(vetor, 0, n - 1);
	clock_gettime(CLOCK_MONOTONIC, &a);

	t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

	printf("%u\n", t);

	free(vetor);

	return 0;
}
