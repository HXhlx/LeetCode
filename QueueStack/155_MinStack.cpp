#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class MinStack
{
    stack<int> s, ms;

public:
    MinStack()
    {
        ms.emplace(INT_MAX);
    }
    void push(int val)
    {
        s.emplace(val);
        ms.emplace(min(ms.top(), val));
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
    int getMin()
    {
        return ms.top();
    }
};