/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 007            --
                        -- Reg. Number : 2019831074     --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Evaluate a Postfix Expression                                 |
        -----------------------------------------------------------------
*/

#include <stdio.h>

#define MAX_SIZE 100000

struct STACK
{
    int MAX_SIZ = 10000, cur_size = 0, value[10000];

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
        return value[cur_size - 1];
    }
};

int evaluate_postfix_expression(char given_expression[])
{
    struct STACK st;

    int i, j, value_of_each_number = 0, positional_value = 1, isFound = 0;
    int num1, num2;

    for (i = 0; given_expression[i] != '\0'; i++)
    {
        isFound = 0; // to make sure that we are getting a number
        if (given_expression[i] == ',')
        {
            // extracting the number that needs to be pushed in the stack
            for (j = i - 1; j >= 0; j--)
            {

                // checking if it is a digit
                if (given_expression[j] < '0' || given_expression[j] > '9')
                    break;

                isFound = 1; // marking that we have successfully got a number

                // calculating value by positional value
                value_of_each_number += (int)(given_expression[j] - '0') * positional_value;
                positional_value *= 10;
            }

            if (isFound == 1)
            {
                // printing the pushing steps
                printf(" >>> PUSHING --> %d\n", value_of_each_number);
                st.PUSH(value_of_each_number);
            }

            // resetting the value and positional value
            value_of_each_number = 0;
            positional_value = 1;
        }

        // searching for operators
        else if (given_expression[i] == '+')
        {
            num1 = st.TOP();
            st.POP();
            num2 = st.TOP();
            st.POP();
            printf(" >>> %d %c %d = %d\t[after two pops then one push]\n", num2, given_expression[i], num1, num1 + num2);
            st.PUSH(num1 + num2);
        }
        else if (given_expression[i] == '-')
        {
            num1 = st.TOP();
            st.POP();
            num2 = st.TOP();
            st.POP();
            printf(" >>> %d %c %d = %d\t[after two pops then one push]\n", num2, given_expression[i], num1, num2 - num1);
            st.PUSH(num2 - num1);
        }
        else if (given_expression[i] == '*')
        {
            num1 = st.TOP();
            st.POP();
            num2 = st.TOP();
            st.POP();
            printf(" >>> %d %c %d = %d\t[after two pops then one push]\n", num2, given_expression[i], num1, (num1 * num2));
            st.PUSH(num1 * num2);
        }
        else if (given_expression[i] == '/' || given_expression[i] == '\\')
        {
            num1 = st.TOP();
            st.POP();
            num2 = st.TOP();
            st.POP();
            printf(" >>> %d %c %d = %d\t[after two pops then one push]\n", num2, given_expression[i], num1, num2 / num1);
            st.PUSH(num2 / num1);
        }
        else if (given_expression[i] == '^')
        {
            num1 = st.TOP();
            st.POP();
            num2 = st.TOP();
            st.POP();
            int anss = 1, k;
            for (k = 1; k <= num1; k++)
                anss *= num2;
            printf("%d %c %d = %d\t[after two pops then one push]\n", num2, given_expression[i], num1, anss);
            st.PUSH(num1 + num2);
        }
    }

    return st.TOP();
}

int main()
{

    // declaring a string to store the expression given by the user
    char given_expression[MAX_SIZE];
    int ans;

    printf("\n\n\tWelcome to the POSTFIX EXPRESSION EVALUATION program\n");
    printf("\n\tEnter your postfix expression separated by commas','\n\n\t");
    printf("For example : \" 12, 9, 17, +, *, 57, -, 3, * \"\n\t");
    printf("Which means you have to put a comma(,)\n\tright after the number you have entered\n\n");

    // taking the expression
    printf("\tEnter the expression : \n\t>>> ");
    gets(given_expression);
    printf("\n\n");

    // calculating the ans
    ans = evaluate_postfix_expression(given_expression);

    // printing ans
    printf("\n\n\"%s\" = %d\n", given_expression, ans);

    return 0;
}

// 12, 12, 12, +, *, 12, +, 12, -
