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
    void Swap(int ar, int ac, int br, int bc);
    void PrintTable();
    vector<int> * GetVector();
    void HeapifyUp(int item);
    int MoveUpRow(int row, int column, int item);
    int MoveUpCol(int row, int column, int item);
    void HeapifyDown(int item);
    int MoveDownRow(int row, int column, int item);
    int MoveDownCol(int row, int column, int item);
    int ** m_table;
    int m_rows;
    int m_colums;

};