#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class TripleInOne
{
    array<pair<unique_ptr<int[]>, unsigned>, 3> S;
    unsigned size;

public:
    TripleInOne(int stackSize) : size(stackSize)
    {
        for (pair<unique_ptr<int[]>, unsigned int> &s : S)
            s.first = make_unique<int[]>(stackSize);
    }
    void push(int stackNum, int value)
    {
        if (S[stackNum].second < size)
            S[stackNum].first[S[stackNum].second++] = value;
    }
    int pop(int stackNum)
    {
        return isEmpty(stackNum) ? EOF : S[stackNum].first[--S[stackNum].second];
    }
    int peek(int stackNum)
    {
        return isEmpty(stackNum) ? EOF : S[stackNum].first[S[stackNum].second - 1];
    }
    bool isEmpty(int stackNum)
    {
        return S[stackNum].second == 0;
    }
};
TEST(ThreeInOne, 1)
{
    TripleInOne obj(1);
    obj.push(0, 1);
    obj.push(0, 2);
    EXPECT_EQ(obj.pop(0), 1);
    EXPECT_EQ(obj.pop(0), -1);
    EXPECT_EQ(obj.pop(0), -1);
    EXPECT_TRUE(obj.isEmpty(0));
}
TEST(ThreeInOne, 2)
{
    TripleInOne obj(18);
}