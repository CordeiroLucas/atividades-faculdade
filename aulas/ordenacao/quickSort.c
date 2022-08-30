#include <stdio.h>
#define N 10

void quicksort (int A[], int l, int r);
int partition (int A[], int l, int r);
void troca (int arr[], int i, int j);

int main(void)
{
	int array[N];

	for (int i = 0; i < N; i++) {
		scanf(" %d", &array[i]);
	}

	quicksort(array, 0, N-1);

	for (int i = 0; i < N; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}


void quicksort (int A[], int l, int r) 
{
	if (l < r) {
		int pivotIndex = partition (A, l, r);
		quicksort (A, l, pivotIndex - 1);
		quicksort (A, pivotIndex + 1, r);
	}
}

int partition (int A[], int l, int r)
{
	int pivot =  A[l];
	int i = l;
	for (int j = l + 1; j <= r; j++) {
		if (A[j] <= pivot) { // trocar para ">" para ordenar de forma decrescente
			i++;
			troca (A, i, j);
		}
	}
	troca (A, l, i);
	
	return i;
}

void troca (int arr[], int i, int j) 
{
	int aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}