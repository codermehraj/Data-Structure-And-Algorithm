/*
    Md. Mehrajul Islam
    2019831074
*/

#include <stdio.h>

#define MAX_SIZE 10000
#define MINUS_INF -99999999

int A[MAX_SIZE];

void printStep(int A[], int stepNumber){
    int i;
    printf("Step %d : ", stepNumber);
    for(i = 1; i <= stepNumber; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void INSERTION(int A[],int N){
    int TEMP, K, PTR;
    A[0] = MINUS_INF;
    printStep(A, 1);
    for(K = 2; K <= N; K++){
        TEMP = A[K];
        PTR = K - 1;
        while(TEMP < A[PTR]){
            A[PTR + 1] = A[PTR]; // mover element further
            PTR = PTR - 1;
        }
        A[PTR + 1] = TEMP;
        printStep(A, K);
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

    INSERTION(A,n);

    printf("\n\nFINAL ARRAY AFTER RUNNING INSERTION SORT :\n");
    for(i = 1; i <= n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

/*

    Algorithm 9.1: (Insertion Sort) INSERTION(A, N).
    This algorithm sorts the array A with N elements.
    1. Set A[0] := – . [Initializes sentinel element.]
    2. Repeat Steps 3 to 5 for K = 2, 3, …, N:
    3. Set TEMP := A[K] and PTR := K – 1.
    4. Repeat while TEMP < A[PTR]:
    (a) Set A[PTR + 1] := A[PTR]. [Moves
    element forward.]
    (b) Set PTR := PTR – 1.
    [End of loop.]
    5. Set A[PTR + 1] := TEMP. [Inserts element in
    proper place.]
    [End of Step 2 loop.]
    6. Return.

*/
