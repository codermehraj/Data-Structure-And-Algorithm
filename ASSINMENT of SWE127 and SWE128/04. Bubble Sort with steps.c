
/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 004            --
                        -- Reg Number  : 2019831074     --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Bubble Sort:                                                  |
        | 1. Sort an array                                              |
        | 2. Count the number of comparisons                            |
        | 3. Count the number of interchanges                           |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int array_size, i, j, number_of_comparisons = 0, number_of_interchanges = 0, main_array[10000];

void bubble_sort(int DATA[], int N);

int main()
{
    printf("\n\n\tEnter the size of the array : ");
    scanf("%d", &array_size);

    printf("\n\tNow Enter %d numbers : \n\t >> ", array_size);
    for (i = 0; i < array_size; i++)
    {
        scanf("%d", &main_array[i]);
    }

    bubble_sort(main_array, array_size);

    // printing the sorted array
    printf("\n\tAfter sorting %d numbers : \n\t >> ", array_size);
    for (i = 0; i < array_size; i++)
    {
        printf("%d ", main_array[i]);
    }

    // printing other credentials
    printf("\n\n\tNUMBER OF COMPARISONS = %d", number_of_comparisons);
    printf("\n\tNUMBER OF INTERCHANGES = %d\n", number_of_interchanges);
    return 0;
}

void bubble_sort(int DATA[], int N)
{
    int PTR, K, temp;
    for (K = 1; K < N; K++)
    {
        for (PTR = 0; PTR < (N - K); PTR++)
        {
            // comaprison
            number_of_comparisons++;
            if (DATA[PTR] > DATA[PTR + 1])
            {
                // interchange
                number_of_interchanges++;
                temp = DATA[PTR];
                DATA[PTR] = DATA[PTR + 1];
                DATA[PTR + 1] = temp;
            }
        }
    }
}
