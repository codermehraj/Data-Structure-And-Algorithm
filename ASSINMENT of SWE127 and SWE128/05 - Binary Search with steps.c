/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 005            --
                        -- Reg Number  : 2019831074     --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Binary Search:                                                |
        | 1. Search an element                                          |
        | 2. Print all steps of searching                               |
        | 3. Print the total number of steps                            |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int array_size, main_array[10000];

void bubble_sort(int DATA[], int N);
void BinarySearch(int DATA[], int LB, int UB, int ITEM, int* LOC);

int main()
{
    int i, desired_number, index;

    // taking the array size
    printf("\n\n\tEnter the number of element in the array : ");
    scanf("%d",&array_size);

    // taking the elements of the array
    printf("\n\tNow Enter %d numbers : \n\t >> ", array_size);
    for (i = 0; i < array_size; i++)
    {
        scanf("%d", &main_array[i]);
    }

    // making sure that it is sorted before doing binary search
    bubble_sort(main_array, array_size);

    // printing the sorted array
    printf("\n\tAfter sorting %d numbers : \n\t >> ", array_size);
    for (i = 0; i < array_size; i++)
    {
        printf("%d ", main_array[i]);
    }

    // taking the desired number
    printf("\n\n\tEnter the number that you want to search in the array : ");
    scanf("%d",&desired_number);

    BinarySearch(main_array, 0, array_size - 1, desired_number, &index);

    if(index == -1) printf("\n\t%d was not found\n\n",desired_number);
    else printf("\n\t%d was found at index = %d [after sorting]\n\n",desired_number,index+1);
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
            if (DATA[PTR] > DATA[PTR + 1])
            {
                // interchange
                temp = DATA[PTR];
                DATA[PTR] = DATA[PTR + 1];
                DATA[PTR + 1] = temp;
            }
        }
    }
}

void BinarySearch(int DATA[], int LB, int UB, int ITEM, int* LOC)
{
    int STEP=0, BEG = LB, END = UB, MID = (BEG+END)/2;
    while(BEG <= END && DATA[MID] != ITEM){
        STEP++;
        printf("\n\n\tSTEP %d :",STEP);
        printf("\tBEG : %d ",BEG+1);
        printf("\tMID : %d ",MID+1);
        printf("\tEND : %d ",END+1);
        if(ITEM < DATA[MID]){
            END = MID  - 1;
        }
        else {
            BEG = MID + 1;
        }
        MID = (BEG + END) / 2;
    }
    if(DATA[MID] == ITEM){
        STEP++;
        printf("\n\n\tSTEP %d :",STEP);
        printf("\tBEG : %d ",BEG+1);
        printf("\tMID : %d ",MID+1);
        printf("\tEND : %d ",END+1);
        *LOC = MID;
    }
    else{
        *LOC = -1;
    }
    printf("\n\n\tTotal Steps : %d\n",STEP);
}
