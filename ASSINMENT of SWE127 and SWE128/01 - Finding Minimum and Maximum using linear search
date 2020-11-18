/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 001            --
                        -- Reg Number  : 2019831074     --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Find the largest and the smallest data from a dataset using   |
        | linear search.                                                |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int main()
{
    int K, LOC_MAX, LOC_MIN, MAX, MIN, N, i;

    printf("Enter the size of the array : ");
    scanf("%d", &N);

    int DATA[N];
    printf("Enter the elements of the array : \n >> ");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &DATA[i]);
    }

    MAX = MIN = DATA[0]; // Initializing MIN and MAX with the first element in the array
    LOC_MAX = LOC_MIN = 1;

    for (K = 1; K < N; K++)
    {
        // cheking for the maximum number
        if (MAX < DATA[K])
        {
            LOC_MAX = K + 1;
            MAX = DATA[K];
        }

        // cheking for the minimum number
        if (MIN > DATA[K])
        {
            LOC_MIN = K + 1;
            MIN = DATA[K];
        }
    }

    printf("\n\n\tMaximum Element is %d\n\twhich is found at index = %d\n", MAX, LOC_MAX);
    printf("\n\n\tMinimum Element is %d\n\twhich is found at index = %d\n\n", MIN, LOC_MIN);

    return 0;
}
