// !/usr/bin/gcc

#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;


	//declaring size of temporary arrays to be created
	
	int n1 = m - l + 1, n2 = r - m;
	int L[n1], R[n2];

	//copy the data to arrays L and R
	//take care of the indexes
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	
	//merge the temp arrays back to arr
	i = j = 0;
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) 
			arr[k++] = L[i++];
		else 
			arr[k++] = R[j++];
	}
	
	//copy the remaining elements of L[], if any
	while (i < n1) 
		arr[k++] = L[i++];

	//copy the remaining elements of R[], if any
	while (j < n2)
		arr[k++] = R[j++];
	
}

void mergeSort(int *arr, int l, int r)
{
	if (l < r) {
		int m =  (r + l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n], i;
	for(i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	mergeSort(arr, 0, n-1);

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	
	printf("\n");

	return 0;
}
