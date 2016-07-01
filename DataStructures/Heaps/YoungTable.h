#pragma once
#include <iostream>
#include <vector>
#define INFINITY 65535

using namespace std;

class YoungTable
{
public:
    YoungTable(int rows, int colums);
    int ExtractMin();
    void Insert(int item);
   
    //Test functions
    void PrintTable();
    vector<int> * GetVector();
    void Validate();
private:
    void Swap(int ar, int ac, int br, int bc);
    void MoveUp(int row, int col, int item);

    int ** m_table;
    int m_rows;
    int m_colums;

};