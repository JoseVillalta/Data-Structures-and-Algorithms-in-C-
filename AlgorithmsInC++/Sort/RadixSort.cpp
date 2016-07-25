#include "RadixSort.h"
#include <string>
#include <vector>

using namespace std;

//LSD String Sort
//Sedgewick Algorithms 4th edition
void RadixSort::Sort(string arr[], int width, int length)
{
    string * aux = new string[length+1];
    for (int i = 0; i < length + 1; i++)
        aux[i] = " ";

    int r = 256;
    
    for (int d = width - 1; d >= 0; d--)
    {
        int * count = new int[r + 1];
        for (int i = 0; i < r + 1; i++)
            count[i] = 0;

        //count frequency
        for (int i = 0; i < length; i++)
           count[arr[i].at(d) + 1]++;     

        //transform count to index
        for (int i = 0; i < r; i++)
            count[i + 1] += count[i];
        
        //Distribute the data
        for (int i = 0; i < length; i++)    
           aux[count[arr[i].at(d)]++] = arr[i];
        
        //copy data back
        for (int i = 0; i < length; i++)
            arr[i] = aux[i];       
    }


}