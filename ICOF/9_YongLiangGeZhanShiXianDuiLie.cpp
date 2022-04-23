#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class CQueue
{
    stack<int> s1, s2;

public:
    CQueue() = default;
    void appendTail(int value)
    {
        while (!s2.empty())
        {
            s1.emplace(s2.top());
            s2.pop();
        }
        s1.emplace(value);
    }
    int deleteHead()
    {
        while (!s1.empty())
        {
            s2.emplace(s1.top());
            s1.pop();
        }
        if (s2.empty())
            return EOF;
        int res = s2.top();
        s2.pop();
        return res;
    }
};