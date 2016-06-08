#pragma once
#include <string>
#include <tuple>

using namespace std;

class SortableRecord
{
public:
    int m_studentNum;
    string m_studenName;

    SortableRecord(int studentNum = 0, string studentName = " ")
    {
        m_studentNum = studentNum;
        m_studenName = studentName;
    }

    bool operator<(const SortableRecord& sr) const
    {
        return tie(m_studentNum, m_studenName) < tie(sr.m_studentNum, sr.m_studenName);
    }

    bool operator>(const SortableRecord& sr) const
    {
        return tie(sr.m_studentNum, sr.m_studenName) < tie(m_studentNum, m_studenName);
    }

    bool operator<=(const SortableRecord& sr) const
    {
        return !(tie(sr.m_studentNum, sr.m_studenName) < tie(m_studentNum, m_studenName));
    }

    bool operator>=(const SortableRecord& sr) const
    {
        return !(tie(m_studentNum, m_studenName) < tie(sr.m_studentNum, sr.m_studenName));
    }

    bool operator==(const SortableRecord& sr) const
    {
        return tie(m_studentNum, m_studenName) == tie(sr.m_studentNum, sr.m_studenName);
    }

    bool operator!=(const SortableRecord& sr) const
    {
        return !(tie(m_studentNum, m_studenName) == tie(sr.m_studentNum, sr.m_studenName));
    }
};