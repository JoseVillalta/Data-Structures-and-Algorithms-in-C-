#ifndef __LINEAR_SEARCH_H__
#define __LINEAR_SEARCH_H__
#include <vector>

using namespace std;
class LinearSearch
{
public:
    template<typename T>
    bool Search(vector<T>& v, T item, int& loc);
    template<typename T>
    bool SelfOrganizingListSearch(vector<T>& v, T item, int& loc);
private:
    template<typename T>
    void Shift(int index, vector<T>& v);
    template<typename T>
    void Reverse(int start, int end, vector<T>& v);
};


#endif