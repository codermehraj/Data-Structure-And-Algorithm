/*
    Algorithm 2.1: (Largest Element in Array) 
    
    A nonempty array DATA with N numerical values is given.
    This algorithm finds the location LOC and the value MAX of the largest element of DATA.
    The variable K is used as a counter.
    
    Step 1: [Initialize.] 
            Set K : = 1, LOC : = 1 and MAX : = DATA[1].
    Step 2: [Increment counter.]
            Set K : = K + 1.
    Step 3: [Test counter.] 
            If K > N, then:
                Write: LOC, MAX, and Exit.
    Step 4: [Compare and update.]
            If MAX < DATA[K], then:
               Set LOC : = K and MAX : = DATA[K].
    Step 5: [Repeat loop.] Go to Step 2.
*/

#include <stdio.h>

int main()
{
    int K, LOC, MAX, N, i;

    printf("Enter the size of the array : ");
    scanf("%d", &N);

    int DATA[N];
    printf("Enter the elements of the array : \n >> ");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &DATA[i]);
    }

    MAX = DATA[0];
    LOC = 1;

    for (K = 1; K < N; K++)
    {
        if (MAX < DATA[K])
        {
            LOC = K + 1;
            MAX = DATA[K];
        }
    }

    printf("Maximum Element is %d which is found at index = %d\n", MAX, LOC);

    return 0;
}
