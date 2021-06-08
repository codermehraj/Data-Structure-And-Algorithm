/*
    Md. Mehrajul Islam
    2019831074
*/

#include <stdio.h>

#define MAX_SIZE 10000
#define INF 99999999

int A[MAX_SIZE], LOWER[MAX_SIZE], UPPER[MAX_SIZE], stepnumber = 1;

void printStep(int A[], int x, int stepNumber){
    int i;
    printf("Step %d : ", stepNumber);
    for(i = 1; i <= x; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int QUICK(int A[], int N, int BEG, int END, int LOC){
    int LEFT = BEG, RIGHT = END, TEMP;
    LOC = BEG;
    while(1){
        while(A[LOC] <= A[RIGHT] && LOC != RIGHT) RIGHT = RIGHT - 1;
        if(LOC == RIGHT) return LOC;
        if(A[LOC] > A[RIGHT]){
            TEMP = A[LOC];
            A[LOC] = A[RIGHT];
            A[RIGHT] = TEMP;
            printf(">>> %d and %d are swapped :\n", A[LOC], A[RIGHT]);
            LOC = RIGHT;
            printStep(A, N, stepnumber++);
        }
        while(A[LOC] >= A[LEFT] && LOC != LEFT) LEFT = LEFT + 1;
        if(LOC == LEFT) return LOC;
        if(A[LOC] < A[LEFT]){
            TEMP = A[LOC];
            A[LOC] = A[LEFT];
            A[LEFT] = TEMP;
            printf(">>> %d and %d are swapped :\n", A[LOC], A[LEFT]);
            LOC = LEFT;
            printStep(A, N, stepnumber++);
        }
    }
}

void QUICK_SORT(int A[],int N){
    if(N < 2) return;
    int TOP = 1, BEG, END, LOC;
    LOWER[1] = 1; UPPER[1] = N;
    while(TOP > 0){
        BEG = LOWER[TOP];
        END = UPPER[TOP];
        TOP = TOP - 1;
        printf("Calling QUICK(%d,%d)\n",BEG, END);
        LOC = QUICK(A,N,BEG,END,LOC);
        printf("Returned from QUICK(%d,%d), LOC of %d = %d\n\n", BEG, END, A[LOC], LOC);
        if(BEG < LOC -1){
            TOP = TOP + 1;
            LOWER[TOP] = BEG;
            UPPER[TOP] = LOC - 1;
        }
        if(LOC + 1 < END){
            TOP = TOP + 1;
            LOWER[TOP] = LOC + 1;
            UPPER[TOP] = END;
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

    QUICK_SORT(A,n);

    printf("\n\nFINAL ARRAY AFTER RUNNING QUICK SORT :\n");
    for(i = 1; i <= n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

/*

    Procedure 6.7: QUICK(A, N, BEG, END, LOC)
    Here A is an array with N elements. Parameters BEG
    and END contain the boundary values of the sublist of A
    to which this procedure applies. LOC keeps track of the
    position of the first element A[BEG] of the sublist
    during the procedure. The local variables LEFT and
    RIGHT will contain the boundary values of the list of
    elements that have not been scanned.
    1. [Initialize.] Set LEFT := BEG, RIGHT := END and
    LOC := BEG.
    2. [Scan from right to left.]
    (a) Repeat while A[LOC) <= A[RIGHT] and
    LOC != RIGHT:
    RIGHT := RIGHT – 1.
    [End of loop.]
    (b) If LOC = RIGHT, then: Return.
    (c) If A[LOC] > A[RIGHT], then:
    (i) [Interchange A[LOC) and
    A[RIGHT].]
    TEMP := A[LOC), A[LOC] :=
    A[RIGHT),
    A[RIGHT] := TEMP.
    (ii) Set LOC := RIGHT.
    (iii) Go to Step 3.
    [End of If structure.]
    3. [Scan from left to right.]
    (a) Repeat while A[LEFT] <= A[LOC) and
    LEFT != LOC:
    LEFT := LEFT + 1.
    [End of loop.]
    (b) If LOC = LEFT, then: Return.
    (c) If A[LEFT] > A[LOC], then
    (i) [Interchange A[LEFT] and A[LOC].]
    TEMP := A[LOC], A[LOC] :=
    A[LEFT],
    A[LEFT] := TEMP.
    (ii) Set LOC := LEFT.
    (iii) Go to Step 2.
    [End of If structure.]
    Algorithm 6.8: (Quicksort) This algorithm sorts an array A with N
    elements.
    1. [Initialize.] TOP := NULL.
    2. [Push boundary values of A onto stacks when A has 2
    or more elements.]
    If N > 1, then: TOP := TOP + 1, LOWER[1] := 1,
    UPPER[1] := N.
    3. Repeat Steps 4 to 7 while TOP != NULL.
    4. [Pop sublist from stacks.]
    Set BEG := LOWER[TOP], END := UPPER[TOP],
    TOP := TOP – 1.
    5. Call QUICK(A, N, BEG, END, LOC). [Procedure
    6.5.]
    6. [Push left sublist onto stacks when it has 2 or more
    elements.]
    If BEG < LOC – 1, then:
    TOP := TOP + 1, LOWER[TOP] := BEG,
    UPPER[TOP] = LOC – 1.
    [End of If structure.]
    7. [Push right sublist onto stacks when it has 2 or more
    elements.]
    If LOC + 1 < END, then:
    TOP := TOP + 1, LOWER[TOP] := LOC + 1,
    UPPER[TOP] := END.
    [End of If structure.]
    [End of Step 3 loop.]
    8. Exit.

*/
