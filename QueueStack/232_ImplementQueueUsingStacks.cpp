#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class MyQueue
{
    stack<int> s1, s2;
    int front = INT_MIN;

public:
    MyQueue() = default;
    void push(int x)
    {
        if (s1.empty())
            front = s2.empty() ? x : s2.top();
        while (!s2.empty())
        {
            s1.emplace(s2.top());
            s2.pop();
        }
        s1.emplace(x);
    }
    int pop()
    {
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
TEST(ImplementQueueUsingStacks, 1)
{
    MyQueue myQueue;
    myQueue.push(1);               // queue is: [1]
    myQueue.push(2);               // queue is: [1, 2] (leftmost is front of the queue)
    EXPECT_EQ(myQueue.peek(), 1);  // return 1
    EXPECT_EQ(myQueue.pop(), 1);   // return 1, queue is [2]
    EXPECT_FALSE(myQueue.empty()); // return false
}