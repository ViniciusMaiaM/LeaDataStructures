#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void distribution_sort(int *v, int n)
{
  int i;
  int max = v[0];
  int min = v[0];

  for (i = 1; i < n; i++)
  {
    if (v[i] > max)
    {
      max = v[i];
    }
    if (v[i] < min)
    {
      min = v[i];
    }
  }

  // Allocate a number of elements of all initialized at 0.
  int *c = (int *)calloc((max - min + 1), sizeof(int));
  int *w = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
  {
    c[v[i] - min]++;
  }

  for (i = 1; i < (max - min + 1); i++)
  {
    c[i] += c[i - 1];
  }

  for (i = n - 1; i >= 0; i--)
  {
    int d = v[i] - min;
    w[c[d] - 1] = v[i];
    c[d] -= 1;
  }

  for (int i = 0; i < n; i++)
  {
    v[i] = w[i];
  }

  free(c);
  free(w);
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
  distribution_sort(vetor, n);
  clock_gettime(CLOCK_MONOTONIC, &a);

  t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

  printf("%u\n", t);

  free(vetor);

  return 0;
}
