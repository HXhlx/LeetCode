#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class MyCircularQueue
{
    unique_ptr<int[]> Queue;
    size_t front = 0, length = 0, capacity;

public:
    MyCircularQueue(int k) : capacity(k)
    {
        Queue.reset(new int[k]);
    }
    bool enQueue(int value)
    {
        if (isFull())
            return false;
        Queue[(front + length++) % capacity] = value;
        return true;
    }
    bool deQueue()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % capacity;
        --length;
        return true;
    }
    int Front()
    {
        return isEmpty() ? EOF : Queue[front];
    }
    int Rear()
    {
        return isEmpty() ? EOF : Queue[(front + length - 1) % capacity];
    }
    bool isEmpty()
    {
        return length == 0;
    }
    bool isFull()
    {
        return length == capacity;
    }
};