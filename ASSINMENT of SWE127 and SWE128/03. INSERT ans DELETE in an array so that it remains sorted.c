/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 003            --
                        -- Reg Number  : 2019831074     --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Array Manipulation:                                           |
        | 1. Sort the array                                             |
        | 2. Insert new element so that array remains sorted            |
        | 3. Delete an element so that array remains sorted             |
        -----------------------------------------------------------------
*/

#include <stdio.h>

int main_array[100000], array_size;

void sort_array();
void insert_number(int num);
void delete_from_array(int num);

int main()
{
    int i, j, num;

    // taking the array size
    printf("\n\tEnter the size of the array : ");
    scanf("%d", &array_size);

    // taking the array from the user
    printf("\n\tEnter the %d numbers : \n\t >> ", array_size);
    for (i = 0; i < array_size; i++)
    {
        scanf("%d", &main_array[i]);
    }

    // sorting the array
    sort_array();

    // printing the sorted array
    printf("\n\tThe sorted array is : \n\t >> ");
    for (i = 0; i < array_size; i++)
    {
        printf("%d ", main_array[i]);
    }

    // insertion
    printf("\n\n\tEnter the number that you want to insert : ");
    scanf("%d", &num);
    insert_number(num); // inserting num into the proper palace
    array_size++;

    // printing the array after insertion
    printf("\n\n\tThe array after inserting %d is : \n\t >> ", num);
    for (i = 0; i < array_size; i++)
    {
        printf("%d ", main_array[i]);
    }

    printf("\n\n\tEnter the value that you want to delete : ");
    scanf("%d", &num);
    delete_from_array(num);
    array_size--;

    // printing the array after deletion
    printf("\n\n\tThe array after deleting %d is : \n\t >> ", num);
    for (i = 0; i < array_size; i++)
    {
        printf("%d ", main_array[i]);
    }

    printf("\n\n");

    return 0;
}

// function to insert num into the correct place
void insert_number(int num)
{
    int i, j, temp, found = 0, temp1;
    for (i = 0; i <= array_size; i++)
    {
        // if found already
        if (found == 1)
        {
            // shifts 1 cell right
            if (i < array_size)
            {
                temp1 = temp;
                temp = main_array[i];
                main_array[i] = temp1;
            }
            else
            {
                // last element
                main_array[i] = temp;
            }
        }
        else if (i == array_size)
        {
            // num is the biggest
            main_array[i] = num;
        }
        else if (main_array[i] >= num)
        {
            // found the place of insertion
            found = 1;
            temp = main_array[i];
            main_array[i] = num;
        }
    }
}

// function to delete num from the array
void delete_from_array(int num)
{
    int i, found = 0;
    for (i = 0; i < array_size; i++)
    {
        if (found == 0 && main_array[i] == num)
            found = 1;
        else if (found == 1)
        {
            main_array[i - 1] = main_array[i];
        }
    }
}

// using bubble sort to sort the array
void sort_array()
{
    int i, j, temp;
    for (i = 0; i < array_size; i++)
    {
        for (j = i + 1; j < array_size; j++)
        {
            if (main_array[i] > main_array[j])
            {
                temp = main_array[j];
                main_array[j] = main_array[i];
                main_array[i] = temp;
            }
        }
    }
}
