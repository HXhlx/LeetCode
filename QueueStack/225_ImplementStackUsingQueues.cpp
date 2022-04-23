#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class MyStack
{
    queue<int> Queue;

public:
    MyStack() = default;
    void push(int x)
    {
        Queue.emplace(x);
    }
    int pop()
    {
        size_t n = Queue.size() - 1, p = Queue.back();
        for (size_t i = 0; i < n; ++i)
        {
            Queue.emplace(Queue.front());
            Queue.pop();
        }
        Queue.pop();
        return p;
    }
    int top()
    {
        return Queue.back();
    }
    bool empty()
    {
        return Queue.empty();
    }
};