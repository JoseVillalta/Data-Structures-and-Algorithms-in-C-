#include "permute_string.h"
#include <iostream>

using namespace std;

void swap(string &a, int l, int r)
{
    auto temp = a[l];
    a[l] = a[r];
    a[r] = temp;
}

void permute(string &a, int l, int r)
{
    if (l == r)
    {
        cout << a << endl;
    }
    else
    {
        for (int i = 0; i <= r; i++)
        {
            swap(a, l, i);
            permute(a, l + 1, r);
            swap(a, l, i);
        }
    }
}