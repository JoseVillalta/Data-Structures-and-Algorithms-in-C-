#include "CountingSort.h"



void CountingSort::Sort(int * IN, int * OUT, int len, int k)
{
    int * B = new int[k];
    for (int i = 0; i < k; i++)
    {
        B[i] = 0;
    }

    for (int i = 0; i < len; i++)
    {
        B[IN[i]]++;
    }


    int index = 0;
    for (int i = 0; i < len; i++)
    {
        while (B[i] > 0)
        {
            OUT[index] = i;
            index++;
            B[i] = B[i] - 1;
        }
    }

}