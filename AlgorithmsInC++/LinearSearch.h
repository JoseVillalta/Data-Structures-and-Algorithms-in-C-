#ifndef __LINEAR_SEARCH_H__
#define __LINEAR_SEARCH_H__
#include <vector>

using namespace std;
class LinearSearch
{
public:
    template<typename T>
    bool Search(vector<T>& v, T item, int& loc);
};


#endif