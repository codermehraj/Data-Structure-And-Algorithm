/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 009            --
                        -- Reg. Number : 2019831074     --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Recursion                                                     |
        | 1. Factorial Calculation                                      |
        -----------------------------------------------------------------
*/

#include <stdio.h>

long long fact(long long n)
{
    if (n <= 1)
        return 1;
    return fact(n - 1) * n;
}

int main()
{
    int n;
    printf("\n\n\tEnter the value of n to calculate n!\n\n\tn = ");
    scanf("%d", &n);
    printf("\n\tvalue of %d! factorial is %lld\n\n", n, fact((long long)n));
}
