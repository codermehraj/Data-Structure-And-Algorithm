/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 002            --
                        -- Reg Number  : 2019831074     --
        -----------------------------------------------------------------
        |  Problem Statement :                                           |
        |----------------------------------------------------------------|
        | String Processing:                                             |
        | Implement substring, indexing, length, insert, delete, replace |
        | concatenate functions of string.                               |
        ------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

char s[10000];

// Function Prototypes
int menu();
int LENGTH(char str[]);
void SUBSTRING(char s[], int initial_position, int substring_length);
void DELETE(char s[], int initial_position, int substring_length);
int INDEX(char main[], char pattern[]);
void INSERT(char main[], int pos, char pattern[]);
void CONCATENATE(char start_string[], char end_string[]);

// The main function
int main()
{
    while (1)
    {
        int menu_choice = menu();
        if (menu_choice == 1)
        {
            // substring
            system("cls");
            printf("\n\n\tEnter the main string : ");
            gets(s);
            int len = LENGTH(s), initial_position, substring_length;
            printf("\n\tEnter the initial position of the substring from the main string : ");
            do
            {
                printf("\n\n\tEnter a number between %d and %d : ", 1, len);
                scanf("%d", &initial_position);
            } while (initial_position < 1 || initial_position > len);
            len = len - initial_position + 1;
            printf("\n\tEnter the size of the sub-string : ");
            do
            {
                printf("\n\n\tEnter a number between %d and %d : ", 1, len);
                scanf("%d", &substring_length);
            } while (substring_length < 1 || substring_length > len);
            printf("\n\tSUBSTRING('%s',%d,%d) = ", s, initial_position, substring_length);
            SUBSTRING(s, initial_position - 1, substring_length);
            printf("'%s'\n", s);
            getchar();
            printf("\n\tpress enter to continue... ");
            getchar();
        }

        if (menu_choice == 2)
        {
            // Index Finding
            system("cls");
            printf("\n\n\tEnter the main string : ");
            gets(s);
            int lenMain = LENGTH(s), ans = 0;
            char pattern[10000];
            printf("\n\n\tEnter the string that you want to search : ");
            gets(pattern);
            ans = INDEX(s, pattern);
            if (ans == 0)
            {
                printf("\n\t'%s' was not found in '%s' \n", pattern, s);
            }
            else
            {
                printf("\n\t'%s' was found in '%s' at %dth index\n", pattern, s, ans);
            }
            printf("\n\n\tPress enter to continue...");
            getchar();
        }
        if (menu_choice == 3)
        {
            // Length
            system("cls");
            printf("\n\n\tEnter the string : ");
            gets(s);
            printf("\n\tLength of '%s' is = %d\n\n\t", s, LENGTH(s));
            printf("press enter to continue... ");
            getchar();
        }
        if (menu_choice == 4)
        {
            // insert
            system("cls");
            printf("\n\n\tEnter the main string : ");
            gets(s);
            int lenMain = LENGTH(s), pos;
            char pattern[10000];
            printf("\n\n\tEnter the string that you want to insert : ");
            gets(pattern);
            printf("\n\tEnter the position where you want to insert : ");
            do
            {
                printf("\n\n\tEnter a number between %d and %d : ", 1, lenMain);
                scanf("%d", &pos);
            } while (pos < 1 || pos > lenMain);
            printf("\n\tAfter inserting '%s' into '%s' at %dth position we get = ", pattern, s, pos);
            INSERT(s, pos - 1, pattern);
            getchar();
            printf("'%s'\n\n\tPress enter to continue...", s);
            getchar();
        }
        if (menu_choice == 5)
        {
            // delete
            system("cls");
            printf("\n\n\tEnter the main string : ");
            gets(s);
            int len = LENGTH(s), initial_position, substring_length;
            printf("\n\tEnter the initial position of the substring that you want to delete : ");
            do
            {
                printf("\n\n\tEnter a number between %d and %d : ", 1, len);
                scanf("%d", &initial_position);
            } while (initial_position < 1 || initial_position > len);
            len = len - initial_position + 1;
            printf("\n\tEnter the size of the sub-string that you want to delete : ");
            do
            {
                printf("\n\n\tEnter a number between %d and %d : ", 1, len);
                scanf("%d", &substring_length);
            } while (substring_length < 1 || substring_length > len);
            printf("\n\tDELETE('%s',%d,%d) = ", s, initial_position, substring_length);
            DELETE(s, initial_position - 1, substring_length);
            printf("'%s'\n", s);
            getchar();
            printf("\n\tpress enter to continue... ");
            getchar();
        }
        if (menu_choice == 6)
        {
            // replace
            system("cls");
            printf("\n\n\tEnter the main string : ");
            gets(s);
            int lenMain = LENGTH(s), pos;
            char pattern1[10000], pattern2[10000], main[10000];
            printf("\n\n\tEnter the string that you want to change : ");
            gets(pattern1);
            printf("\n\tEnter the the string you want to replace in the place of '%s' : ", pattern1);
            gets(pattern2);
            for (pos = 0; pos < lenMain; pos++)
                main[pos] = s[pos];
            main[lenMain] = '\0';
            pos = INDEX(s, pattern1);
            if (pos == 0)
            {
                printf("\n\t'%s' is not present in '%s'\n", pattern1, s);
            }
            else
            {
                DELETE(s, pos - 1, LENGTH(pattern1));
                INSERT(s, pos - 1, pattern2);
                printf("\n\tAfter replacing '%s' from '%s' by '%s' we get = '%s'", pattern1, main, pattern2, s);
            }
            printf("\n\n\tPress enter to continue...", s);
            getchar();
        }
        if (menu_choice == 7)
        {
            // concatenate
            system("cls");
            printf("\n\n\tEnter the first string : ");
            gets(s);
            char s1[10000];
            printf("\n\n\tEnter the string that you want to concatenate after '%s' : ", s);
            gets(s1);
            printf("\n\tAfter concatenateing '%s' and '%s' we get = ", s, s1);
            CONCATENATE(s, s1);
            printf("'%s'\n\n\tPress enter to continue...", s);
            getchar();
        }
        if (menu_choice == 8)
        {
            system("cls");
            printf("Thanks for using the program\n");
            return 0;
        }
    }
}

int LENGTH(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

// assigns the desired substring into s
void SUBSTRING(char s[], int initial_position, int substring_length)
{
    int i;
    char temp[substring_length];
    for (i = 0; i < substring_length; i++)
        temp[i] = s[initial_position + i];
    for (i = 0; i < substring_length; i++)
        s[i] = temp[i];
    s[substring_length] = '\0';
}

void DELETE(char s[], int initial_position, int substring_length)
{
    int j = 0, i, Len = LENGTH(s);
    char temp[Len - substring_length];
    for (i = 0; i < Len; i++)
    {
        if (i == initial_position)
            i = i + substring_length;
        temp[j++] = s[i];
    }
    Len -= substring_length;
    for (i = 0; i < Len; i++)
        s[i] = temp[i];
    s[Len] = '\0';
}

// returns the index where pattern is found into main else returns 0
int INDEX(char main[], char pattern[])
{
    int i, j, ans = 0, len1 = LENGTH(main), len2 = LENGTH(pattern);
    int found = 0;
    if (len2 > len1)
        return 0;
    for (i = 0; i < len1; i++)
    {
        if ((i + len2 - 1) >= len1)
            break;
        for (j = 0; j < len2; j++)
        {
            if (main[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == len2)
        {
            found = 1;
            ans = i + 1;
            break;
        }
    }
    if (found == 1)
        return ans;
    else
        return 0;
}

void INSERT(char main[], int pos, char pattern[])
{
    int i, j = 0, k, Len, LenA = LENGTH(main), LenB = LENGTH(pattern);
    Len = LenA + LenB;
    char temp[Len];
    for (i = 0; i < LenA; i++)
    {
        if (i == pos)
        {
            for (k = 0; k < LenB; k++)
                temp[j++] = pattern[k];
        }
        temp[j++] = s[i];
    }
    for (i = 0; i < Len; i++)
        s[i] = temp[i];
    s[Len] = '\0';
}

void CONCATENATE(char start_string[], char end_string[])
{
    int i, len1 = LENGTH(start_string), len2 = LENGTH(end_string);
    for (i = 0; i < len2; i++)
        start_string[len1 + i] = end_string[i];
    start_string[len1 + len2] = '\0';
}

int menu()
{
    int err = 0;
    char choice[1000];
    system("cls");
    printf("\n\n __________________________________________________________\n");
    printf(" |------------------STRING PROCESSING----------------------|\n");
    printf(" |.........................................................|\n");
    printf(" |-------------------- <MAIN MENU> ------------------------|\n");
    printf(" |                                                         |\n");
    printf(" |  1 >>> Substring                                        |\n");
    printf(" |  2 >>> Index finding                                    |\n");
    printf(" |  3 >>> Length                                           |\n");
    printf(" |  4 >>> Insert                                           |\n");
    printf(" |  5 >>> Delete                                           |\n");
    printf(" |  6 >>> Replace                                          |\n");
    printf(" |  7 >>> Concatenate                                      |\n");
    printf(" |  8 >>> Exit                                             |\n");
    printf(" ==========================================================\n\n\t");

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

/*

 __________________________________________________________
 |-----------------STRING PROCESSING----------------------|
 |........................................................|
 |-----------------<  MAIN  MENU  >-----------------------|
 |                                                        |
 |  1 >>> Substring                                       |
 |  2 >>> Index finding                                   |
 |  3 >>> Length                                          |
 |  4 >>> Insert                                          |
 |  5 >>> Delete                                          |
 |  6 >>> Replace                                         |
 |  7 >>> Concatenate                                     |
 |  8 >>> Exit                                            |
 ==========================================================
 */
