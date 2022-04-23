#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class MaxQueue
{
    deque<int> q, m;

public:
    MaxQueue() = default;
    int max_value()
    {
        return m.empty() ? EOF : m.front();
    }
    void push_back(int value)
    {
        q.emplace_back(value);
        while (!m.empty() && value >= m.back())
            m.pop_back();
        m.emplace_back(value);
    }
    int pop_front()
    {
        if (q.empty())
            return EOF;
        int p = q.front();
        q.pop_front();
        if (m.front() == p)
            m.pop_front();
        return p;
    }
};