#include "YoungTable.h"

YoungTable::YoungTable(int rows, int columns)
{
    m_rows = rows;
    m_colums = columns;
    m_table = new int *[rows];
    for (int index = 0; index < rows; index++)
    {
        m_table[index] = new int[columns];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            m_table[i][j] = INFINITY;
        }
    }
}


int YoungTable::ExtractMin()
{
    return m_table[0][0];
}

void YoungTable::Insert(int item)
{
    //check if table is full
    if (m_table[m_rows - 1][m_colums - 1] < INFINITY)
    {
        cout << "Cannot insert, table is full" << endl;
        return;
    }

    HeapifyUp(item);
}

void YoungTable::HeapifyUp(int item)
{
    m_table[m_rows - 1][m_colums - 1] = item;
    int col = MoveUpRow(m_rows - 1, m_colums - 1, item);
    MoveUpCol(m_rows - 1, col, item);
}

void YoungTable::HeapifyDown(int item)
{
    m_table[0][0] = item;
    int row = MoveDownCol(0, 0, item);
    MoveDownRow(row, 0, item);
}

int YoungTable::MoveUpRow(int row, int col, int item)
{
    int cur_col = col;
    if (cur_col == 0) return 0;

    if (m_table[row][cur_col - 1] <= item) return cur_col;

    Swap(row, cur_col, row, cur_col - 1);
    return MoveUpRow(row, cur_col - 1, item);
}

int YoungTable::MoveUpCol(int row, int col, int item)
{
    int cur_row = row;
    if (cur_row == 0) return 0;

    if (m_table[row - 1][col] <= item) return cur_row;
    
    Swap(cur_row, col, cur_row - 1, col);
    return MoveUpCol(cur_row - 1, col, item);
}

void YoungTable::Swap(int ar, int ac, int br, int bc)
{
    int temp = m_table[ar][ac];
    m_table[ar][ac] = m_table[br][bc];
    m_table[br][bc] = temp;
}