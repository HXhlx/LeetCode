#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class MinStack
{
    stack<int> s, ms;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        ms.emplace(INT_MAX);
    }
    void push(int val)
    {
        s.emplace(val);
        ms.emplace(::min(ms.top(), val));
    }
    void pop()
    {
        s.pop();
        ms.pop();
    }
    int top()
    {
        return s.top();
    }
    int min()
    {
        return ms.top();
    }
};