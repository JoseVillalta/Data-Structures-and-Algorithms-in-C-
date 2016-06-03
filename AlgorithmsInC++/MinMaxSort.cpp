#include "MinMaxSort.h"
#include "swap.h"

template <typename T>
void MinMaxSort::Sort(vector<T> & v, int start, int end)
{
    int left = start;
    int right = end;

    //rainbow
    while (left < right)
    {
        if (v[left] > v[right])
        {
            swap(v, left, right);
        }
        left++;
        right--;
    }

    int outerLeft = start;
    int outerRight = end;
    int midPoint = (end - start) / 2;
    while (outerLeft < outerRight)
    {
        //find min in first half
        left = outerLeft;
        right = outerRight;
        int minIndex = left;
       
        while (left < midPoint)
        {
            if (v[left] < v[minIndex])
            {
                swap(v, left, minIndex);
            }
            left++;
        }

        left = outerLeft;
        right = outerRight;
        int maxIndex = right;
        while (right > midPoint)
        {
            if (v[right] > v[maxIndex])
            {
                swap(v, right, maxIndex);
            }
            right--;
        }

        //rainbow
        left = outerLeft;
        right = outerRight;
        while (left < right)
        {
            if (v[left] > v[right])
            {
                swap(v, left, right);
            }
            left++;
            right--;
        }

        outerLeft++;
        outerRight--;

    }

    

}

template void MinMaxSort::Sort(vector<int> & v, int start, int end);