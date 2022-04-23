#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
class NestedIterator
{
    stack<pair<vector<NestedInteger>::const_iterator, vector<NestedInteger>::const_iterator>> iters;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        iters.emplace(nestedList.cbegin(), nestedList.cend());
    }
    int next()
    {
        return iters.top().first++->getInteger();
    }
    bool hasNext()
    {
        while (!iters.empty())
        {
            pair<vector<NestedInteger>::const_iterator, vector<NestedInteger>::const_iterator> &p = iters.top();
            if (p.first == p.second)
                iters.pop();
            else if (p.first->isInteger())
                return true;
            else
            {
                auto &l = p.first++->getList();
                iters.emplace(l.begin(), l.end());
            }
        }
        return false;
    }
};