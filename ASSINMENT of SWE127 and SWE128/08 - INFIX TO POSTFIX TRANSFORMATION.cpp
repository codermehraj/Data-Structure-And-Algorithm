/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 008            --
                        -- Reg. Number : 2019831074     --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Transform Infix Expression into Postfix Expression            |
        -----------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

struct STACK
{
    int MAX_SIZ = 1000, cur_size = 0;
    char value[1000][100];

    // pushes num in the top of the stack
    // returns -1 if the stack is full
    // else returns the current size of the stacks
    int PUSH(char num[])
    {
        if (cur_size == MAX_SIZ)
            return -1;
        strcpy(value[cur_size++], num);
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
};

char precedence[] = {'+', '-', '*', '/', '^'};

int LENGTH(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

void CONCATENATE(char start_string[], char end_string[])
{
    int i, len1 = LENGTH(start_string), len2 = LENGTH(end_string);
    for (i = 0; i < len2; i++)
        start_string[len1 + i] = end_string[i];
    start_string[len1 + len2] = '\0';
}

void remove_all_space(char a[])
{
    char temp[MAX_SIZE];
    int i, j = 0;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != ' ')
            temp[j++] = a[i];
    }
    temp[j] = '\0';
    for (i = 0; i < j; i++)
    {
        a[i] = temp[i];
    }
    a[j++] = ')';
    a[j] = '\0';
}

void TRANSFORM_INFIX_TO_POSTFIX(char infix[], char postfix[])
{
    remove_all_space(infix);
    //puts(infix);

    int i, tempSize = 0, postfixSize = 0;
    char temp[1000];
    struct STACK st;
    st.PUSH("(");
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
        {
            st.PUSH("(");
        }
        else if (infix[i] == ')')
        {
            while (1)
            {
                *temp = *st.value[st.cur_size - 1];
                st.POP();
                if (temp[0] == '(')
                    break;
                CONCATENATE(postfix, " ");
                CONCATENATE(postfix, temp);
                CONCATENATE(postfix, " ");
            }
        }
        else if (infix[i] == '^')
        {
            while (1)
            {
                *temp = *st.value[st.cur_size - 1];
                if (temp[0] != '^')
                    break;
                st.POP();
                CONCATENATE(postfix, " ");
                CONCATENATE(postfix, temp);
                CONCATENATE(postfix, " ");
            }
            CONCATENATE(postfix, " ");
            st.PUSH("^");
        }
        else if (infix[i] == '*' || infix[i] == '/')
        {
            while (1)
            {
                *temp = *st.value[st.cur_size - 1];
                if (temp[0] == '(' || temp[0] == '+' || temp[0] == '-')
                    break;
                st.POP();
                CONCATENATE(postfix, " ");
                CONCATENATE(postfix, temp);
                CONCATENATE(postfix, " ");
            }
            CONCATENATE(postfix, " ");
            if (infix[i] == '*')
                st.PUSH("*");
            else
                st.PUSH("/");
        }
        else if (infix[i] == '+' || infix[i] == '-')
        {
            while (1)
            {
                *temp = *st.value[st.cur_size - 1];
                if (temp[0] == '(')
                    break;
                st.POP();
                CONCATENATE(postfix, " ");
                CONCATENATE(postfix, temp);
                CONCATENATE(postfix, " ");
            }
            CONCATENATE(postfix, " ");
            if (infix[i] == '+')
                st.PUSH("+");
            else
                st.PUSH("-");
        }
        else
        {
            // push number
            temp[0] = infix[i];
            temp[1] = '\0';
            CONCATENATE(postfix, temp);
        }
    }
}

int main()
{
    // declaring a string to store the infix expression given by the user
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    int ans;

    printf("\n\n\tWelcome to the INFIX to POSTFIX CONFIRSION program\n");
    printf("\n\tEnter your postfix expression separated by commas','\n\n\t");
    printf("For example : \" ( 12 + 3 ) / 3 * 5 + 2 ^ 2 \"\n\n\t");

    // taking the expression
    printf("Enter the expression : \n\t>>> ");
    gets(infix);
    printf("\n");

    // calculating the ans
    TRANSFORM_INFIX_TO_POSTFIX(infix, postfix);

    printf("\tPOSTFIX :\n\t%s\n", postfix);

    return 0;
}

// ( 12 + 3 ) / 3 * 5 + 2 ^ 2
// ( A + B ) / C * D + E ^ E
