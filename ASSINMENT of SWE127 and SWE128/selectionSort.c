/*
    Md. Mehrajul Islam
    2019831074
*/

#include <stdio.h>

#define MAX_SIZE 10000

int A[MAX_SIZE], stepNum = 1;

void printStep(int A[], int N, int stepNumber){
    int i;
    printf("Step %d : ", stepNumber);
    for(i = 1; i <= N; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int MIN(int A[], int K, int N, int LOC){
    int MINIMUM = A[K], J;
    LOC = K;
    for(J = K + 1; J <= N; J++){
        if(MINIMUM > A[J]){
            MINIMUM = A[J];
            LOC = J;
        }
    }
    return LOC;
}

void SELECTION(int A[],int N){
    int K, LOC, TEMP, PREV_LOC;
    for(K = 1; K < N; K++){
        PREV_LOC = LOC;
        LOC = MIN(A, K, N, LOC);
        TEMP = A[K];
        A[K] = A[LOC];
        A[LOC] = TEMP;
        if(A[LOC] == A[K]) printf("Nothing Swapped : %d is in the correct place\n",A[LOC]);
        else {
            printf("%d and %d are swaped\n", A[K], A[LOC]);
            printStep(A, N, stepNum++);
            printf("\n");
        }
    }
}

int main()
{
    int n, i; // size of the array

    printf("Enter the size of the array : ");
    scanf("%d", &n);

    printf("ENTER %d Numbers : ", n);
    for(i = 1 ; i <= n ; i++){
        scanf("%d", &A[i]); // taking the ith element of the array
    }
    printf("\n");

    SELECTION(A,n);

    printf("\n\nFINAL ARRAY AFTER RUNNING INSERTION SORT :\n");
    for(i = 1; i <= n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

