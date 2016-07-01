#include "YoungTableau.h"

YoungTableau::YoungTableau(int rows, int columns)
{
    m_rows = rows;
    m_cols = columns;
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


int YoungTableau::ExtractMin()
{
    int minVal = m_table[0][0];
    MoveDown(0, 0, INFINITY);
    return minVal;
}

void YoungTableau::Insert(int item)
{
    //check if table is full
    if (m_table[m_rows - 1][m_cols - 1] < INFINITY)
    {
        cout << "Cannot insert, table is full" << endl;
        return;
    }
    m_table[m_rows - 1][m_cols - 1] = item;
    MoveUp(m_rows - 1, m_cols - 1, item);
}


void YoungTableau::MoveUp(int row, int col, int item)
{
    if (row == 0)
    {
        if (col == 0) return;

        if (m_table[row][col - 1] > item)
        {
            Swap(row, col, row, col - 1);
            MoveUp(row, col - 1, item);
        }
    }
    else if (col == 0)
    {
        if (m_table[row - 1][col] > item)
        {
            Swap(row, col, row-1, col);
            MoveUp(row - 1, col, item);
        }
    }
    else
    {
        int nextRow = m_table[row - 1][col];
        int nextCol = m_table[row][col - 1];

        if (nextRow >= nextCol)
        {
            if (nextRow > item)
            {
                Swap(row, col, row - 1, col);
                MoveUp(row - 1, col, item);
            }
            else
            {
                if (nextCol > item)
                {
                    Swap(row, col, row, col - 1);
                    MoveUp(row, col - 1, item);
                }
            }
        }
        else
        {
            if (nextCol > item)
            {
                Swap(row, col, row, col - 1);
                MoveUp(row, col - 1, item);
            }
            else
            {
                if (nextRow > item)
                {
                    Swap(row, col, row - 1, col);
                    MoveUp(row - 1, col, item);
                }

            }
        }
    }
}

void YoungTableau::MoveDown(int row, int col, int item)
{
    if (row == m_rows - 1)
    {
        if (col == m_cols - 1) return;

        if (m_table[row][col + 1] > item)
        {
            Swap(row, col, row, col + 1);
            MoveDown(row, col + 1, item);
        }
    }
    else if (col == m_cols - 1)
    {
        if (m_table[row + 1][col] > item)
        {
            Swap(row, col, row + 1, col);
            MoveDown(row + 1, col, item);
        }
    }
    else
    {
        if (m_table[row + 1][col] > item)
        {
            Swap(row, col, row + 1, col);
            MoveDown(row + 1, col, item);
        }
    }
}

void YoungTableau::Swap(int ar, int ac, int br, int bc)
{
    int temp = m_table[ar][ac];
    m_table[ar][ac] = m_table[br][bc];
    m_table[br][bc] = temp;
}

void YoungTableau::PrintTable()
{
    int val;
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            val = m_table[i][j];
            if (val == INFINITY)
            {
                cout << "., ";
            }
            else
            {
                cout << val << ", ";
            }
            
        }
        cout << endl;
    }
    cout << endl;
}

void YoungTableau::Validate()
{
    for (int i = 0; i < m_rows - 1; i++)
    {
        for (int j = 0; j < m_cols - 1; j++)
        {
            _ASSERT(m_table[i][j] <= m_table[i][j + 1]);
            _ASSERT(m_table[i][j] <= m_table[i + 1][j]);
        }
    }
}