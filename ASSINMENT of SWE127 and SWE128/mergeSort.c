/*
    Md. Mehrajul Islam
    2019831074
*/
#include <stdio.h>

#define MAX_SIZE 999999

int A[MAX_SIZE];

void printArray(int A[], int l, int r)
{
    int i;
	for (i = l; i <= r; i++) printf("%d ",A[i]);
	printf("\n");
}

void merge(int arr[], int l, int m, int r)
{
    printf("[%d, %d] = ", l+1, m+1);
    printArray(arr, l, m);
    printf("[%d, %d] = ", m+2, r+1);
    printArray(arr, m+1, r);

	int n1 = m - l + 1;
	int n2 = r - m , i, j, k;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
    k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	printf("After Merging [%d , %d] = ", l+1, r+1);
	printArray(arr, l, r);
	printf("\n");
}

void mergeSort(int arr[],int l,int r){
	//printf("mergeSort(arr, %d, %d) is called\n", l, r);
	if(l>=r) return;

    int m = l + (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}

int main()
{
	int n, i; // size of the array

    printf("Enter the size of the array : ");
    scanf("%d", &n);

    printf("ENTER %d Numbers : ", n);
    for(i = 0 ; i < n ; i++){
        scanf("%d", &A[i]); // taking the ith element of the array
    }
    printf("\n");

    mergeSort(A,0, n-1);

    printf("\nFINAL ARRAY AFTER RUNNING INSERTION SORT :\n");
    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
	return 0;
}
