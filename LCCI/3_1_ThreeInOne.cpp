#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class TripleInOne
{
    array<shared_ptr<int[]>, 3> Stack;
    array<unsigned, 3> lens{};
    unsigned size;

public:
    TripleInOne(int stackSize) : size(stackSize)
    {
        for (shared_ptr<int[]> &s : Stack)
            s = make_shared<int[]>(stackSize);
    }
    void push(int stackNum, int value)
    {
        if (lens[stackNum] < size)
            Stack[stackNum][lens[stackNum]++] = value;
    }
    int pop(int stackNum)
    {
        return lens[stackNum] ? Stack[stackNum][--lens[stackNum]] : EOF;
    }
    int peek(int stackNum)
    {
        return lens[stackNum] ? Stack[stackNum][lens[stackNum] - 1] : EOF;
    }
    bool isEmpty(int stackNum)
    {
        return lens[stackNum] == 0;
    }
};