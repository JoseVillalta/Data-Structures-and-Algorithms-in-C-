#pragma once

template<typename T>
class ListNode{
public:
    ListNode * next;
    T data;
    ListNode(T val = 0)
    {
        next = nullptr;
        data = val;
    }
};