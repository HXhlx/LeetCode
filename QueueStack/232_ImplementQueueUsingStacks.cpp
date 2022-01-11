#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class MyQueue
{
    stack<int> s1, s2;
    int front;

public:
    MyQueue() = default;
    void push(int x)
    {
        if (s1.empty())
        {
            if (s2.empty())
                front = x;
            else
                while (!s2.empty())
                {
                    s1.emplace(s2.top());
                    s2.pop();
                }
        }
        s1.emplace(x);
    }
    int pop()
    {
        if (s2.empty())
            while (!s1.empty())
            {
                s2.emplace(s1.top());
                s1.pop();
            }
        front = s2.top();
        s2.pop();
        return front;
    }
    int peek()
    {
        return s2.empty() ? front : s2.top();
    }
    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */