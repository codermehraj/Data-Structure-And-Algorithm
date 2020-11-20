/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 006            --
                        -- Reg. Number : 2019831074     --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Stack:                                                        |
        | 1. push() function                                            |
        | 2. pop() function                                             |
        -----------------------------------------------------------------
        As C Structure dont allow member functions thats why I used ".cpp" file format to code this.
        But I used all the C syntax
*/

#include <stdio.h>
#include <stdlib.h>

int menu_choice();

struct STACK
{
    int MAX_SIZ, cur_size, value[10000];

    // pushes num in the top of the stack
    // returns -1 if the stack is full
    // else returns the current size of the stacks
    int PUSH(int num)
    {
        if (cur_size == MAX_SIZ)
            return -1;
        value[cur_size++] = num;
        return cur_size;
    }

    // pops the top value of the stack
    // returns -1 if the stack is empty
    // else returns the current size of the stacks
    int POP()
    {
        if (cur_size == 0)
            return -1;
        cur_size--;
        return cur_size;
    }

    // returns -1 if the stack is empty
    // else returns the current size of the stacks
    int TOP()
    {
        if (cur_size == 0)
            return -1;
        return cur_size;
    }

    // returns the size of the stack
    int SIZE()
    {
        return cur_size;
    }

    // prints the elemenets of the stack
    // returns -1 if the stack is empty
    // else returns the current size of the stacks
    int PRINT()
    {
        if (cur_size == 0)
            return -1;
        printf("\n\n\tYOUR STACK IS : \n");
        int i;
        printf("\n\t>>> TOP <<< \n\n");
        for (i = cur_size - 1; i >= 0; i--)
        {
            printf("\t>>>  %d\n", value[i]);
        }
        printf("\n\t>>> BOTTOM <<< \n");
    }

    // clars the stack
    // if the array is already empty returns -1
    int CLEAR()
    {
        if (cur_size == 0)
            return -1;
        printf("\n\n\t%d elements has been cleared\n\n\t", cur_size);
        printf("Now the stack is empty");
        cur_size = 0;
    }
};

int main()
{
    int choice, num;
    struct STACK st;
    st.cur_size = 0;
    printf("\n\n\tWelcome to the STACK implementation program\n\n\t");
    printf("ENTER THE MAX SIZE OF THE STACK = ");
    scanf("%d", &st.MAX_SIZ);
    printf("Press enter to continue...");
    getchar();
    while (1)
    {
        choice = menu_choice();
        if (choice == 7)
            break;
        else if (choice == 1)
        {
            // PUSH
            system("cls");
            printf("\n\n\tEnter the value that you want to PUSH : ");
            scanf("%d", &num);
            if (st.PUSH(num) == -1)
                printf("\n\n\tSORRY! The stack is fulled already...");
            else
                printf("\n\n\t%d has been pushed into the stack successfully...", num);
            getchar();
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
        else if (choice == 2)
        {
            // POP
            system("cls");
            if (st.POP() == -1)
                printf("\n\n\tSORRY! The stack is already empty...");
            else
                printf("\n\n\t%d has been poped from the stack successfully...", st.value[st.cur_size]);
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
        else if (choice == 3)
        {
            // TOP
            system("cls");
            if (st.TOP() == -1)
                printf("\n\n\tSORRY! The stack is empty...");
            else
                printf("\n\n\t%d is the toppmost value of the stack...", st.value[st.cur_size - 1]);
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
        else if (choice == 4)
        {
            // SIZE
            system("cls");
            printf("\n\n\tSIZE of the stack is : %d", st.SIZE());
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
        else if (choice == 5)
        {
            // PRINT THE STACK
            system("cls");
            if (st.PRINT() == -1)
                printf("\n\n\tSORRY! The stack is empty...");
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
        else if (choice == 6)
        {
            // CLEAR THE STACK
            system("cls");
            if (st.CLEAR() == -1)
                printf("\n\n\tSORRY! The stack is empty...");
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
    printf("  |------------------SATCK IMPEMENTATION--------------------|\n");
    printf("  |.........................................................|\n");
    printf("  |-------------------- <MAIN MENU> ------------------------|\n");
    printf("  |                                                         |\n");
    printf("  |  1 >>> PUSH                                             |\n");
    printf("  |  2 >>> POP                                              |\n");
    printf("  |  3 >>> TOP                                              |\n");
    printf("  |  4 >>> SIZE                                             |\n");
    printf("  |  5 >>> PRINT STACK                                      |\n");
    printf("  |  6 >>> CLEAR STACK                                      |\n");
    printf("  |  7 >>> Exit                                             |\n");
    printf("  ===========================================================\n\n\t");

    do
    {
        if (err == 1)
            printf("\n\t Wrong Input ~ Press any number from 1 - 7 : \n\t");
        printf("Enter your choice : ");
        gets(choice);
        err = 1;
    } while (choice[0] < '1' || choice[0] > '7');

    return (int)(choice[0] - '0');
}
