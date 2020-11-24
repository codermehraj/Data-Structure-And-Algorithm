/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 010            --
                        -- Reg. Number : 2019831074     --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Queue:                                                        |
        | 1. PUSH() function                                         |
        | 2. POP() function                                         |
        -----------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int menu_choice();

struct QUEUE
{
    int MAX_SIZ, cur_size = 0, value[10000], frnt = -1, bck = -1;

    // pushes num in the back of the queue
    // returns -1 if the queue is full
    // else returns the index of the pushed element of queue
    int PUSH(int num)
    {
        if (cur_size == MAX_SIZ)
            return -1;
        if (frnt == -1)
            frnt++;
        cur_size++;
        bck++;
        if (bck == MAX_SIZ)
            bck = 0;
        value[bck] = num;
        return bck;
    }

    // pops the front value of the queue
    // returns -1 if the queue is empty
    // else returns the index of popped element
    int POP()
    {
        if (cur_size == 0)
            return -1;
        cur_size--;
        int x = frnt;
        frnt++;
        if (frnt == MAX_SIZ)
            frnt = 0;
        if (cur_size == 0)
        {
            frnt = -1;
            bck = -1;
        }
        return x;
    }

    // returns -1 if the queue is empty
    // else returns the index of front
    int FRONT()
    {
        if (cur_size == 0)
            return -1;
        return frnt;
    }

    // returns -1 if the queue is empty
    // else returns the index of rear
    int REAR()
    {
        if (cur_size == 0)
            return -1;
        return bck;
    }

    // returns the size of the queue
    int SIZE()
    {
        return cur_size;
    }

    // prints the elemenets of the queue
    // returns -1 if the queue is empty
    // else returns the current size of the queues
    int PRINT()
    {
        if (cur_size == 0)
            return -1;
        printf("\n\n\tYOUR queue IS : \n");
        int i = frnt;
        printf("\n\t>>> FRONT <<< \n\n");
        while (i != bck)
        {
            printf("\t>>>  %d\n", value[i]);
            i++;
            i %= MAX_SIZ;
        }
        printf("\t>>>  %d\n", value[i]);
        printf("\n\t>>> REAR <<< \n");
    }

    // clars the queue
    // if the array is already empty returns -1
    int CLEAR()
    {
        if (cur_size == 0)
            return -1;
        printf("\n\n\t%d elements has been cleared\n\n\t", cur_size);
        printf("Now the queue is empty");
        cur_size = frnt = bck = 0;
    }
};

int main()
{
    int choice, num;
    struct QUEUE Q;
    Q.cur_size = 0;
    printf("\n\n\tWelcome to the QUEUE implementation program\n\n\t");
    printf("ENTER THE MAX SIZE OF THE QUEUE = ");
    scanf("%d", &Q.MAX_SIZ);
    printf("Press enter to continue...");
    getchar();
    while (1)
    {
        choice = menu_choice();
        if (choice == 8)
            break;
        else if (choice == 1)
        {
            // PUSH
            system("cls");
            printf("\n\n\tEnter the value that you want to PUSH : ");
            scanf("%d", &num);
            if (Q.PUSH(num) == -1)
                printf("\n\n\tSORRY! The queue is fulled already...");
            else
                printf("\n\n\t%d has been pushed into the queue successfully...", num);
            getchar();
            printf("\n\n\tNow, Front = %d and Rear = %d", Q.frnt + 1, Q.bck + 1);
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
        else if (choice == 2)
        {
            // POP
            system("cls");
            int x = Q.POP();
            if (x == -1)
                printf("\n\n\tSORRY! The queue is already empty...");
            else
                printf("\n\n\t%d has been popped from the queue successfully...", Q.value[x]);
            printf("\n\n\tNow, Front = %d and Rear = %d", Q.frnt + 1, Q.bck + 1);
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
        else if (choice == 3)
        {
            // FRONT
            system("cls");
            int x = Q.FRONT();
            if (x == -1)
                printf("\n\n\tSORRY! The queue is empty...");
            else
                printf("\n\n\t%d is the front value of the queue...", Q.value[x]);
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
        else if (choice == 4)
        {
            // REAR
            system("cls");
            int x = Q.REAR();
            if (x == -1)
                printf("\n\n\tSORRY! The queue is empty...");
            else
                printf("\n\n\t%d is the rear value of the queue...", Q.value[x]);
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
        else if (choice == 5)
        {
            // SIZE
            system("cls");
            printf("\n\n\tSIZE of the queue is : %d", Q.SIZE());
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
        else if (choice == 6)
        {
            // PRINT THE queue
            system("cls");
            if (Q.PRINT() == -1)
                printf("\n\n\tSORRY! The queue is empty...");
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
        else if (choice == 7)
        {
            // CLEAR THE queue
            system("cls");
            if (Q.CLEAR() == -1)
                printf("\n\n\tSORRY! The queue is empty...");
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
    }

    return 0;
}

int menu_choice()
{
    int err = 0;
    char choice[1000];
    system("cls");
    printf("\n\n  ___________________________________________________________\n");
    printf("  |------------------QUEUE IMPEMENTATION--------------------|\n");
    printf("  |.........................................................|\n");
    printf("  |-------------------- <MAIN MENU> ------------------------|\n");
    printf("  |                                                         |\n");
    printf("  |  1 >>> PUSH                                             |\n");
    printf("  |  2 >>> POP                                              |\n");
    printf("  |  3 >>> FRONT                                            |\n");
    printf("  |  4 >>> REAR                                             |\n");
    printf("  |  5 >>> SIZE                                             |\n");
    printf("  |  6 >>> PRINT QUEUE                                      |\n");
    printf("  |  7 >>> CLEAR QUEUE                                      |\n");
    printf("  |  8 >>> Exit                                             |\n");
    printf("  ===========================================================\n\n\t");

    do
    {
        if (err == 1)
            printf("\n\t Wrong Input ~ Press any number from 1 - 8 : \n\t");
        printf("Enter your choice : ");
        gets(choice);
        err = 1;
    } while (choice[0] < '1' || choice[0] > '8');

    return (int)(choice[0] - '0');
}
