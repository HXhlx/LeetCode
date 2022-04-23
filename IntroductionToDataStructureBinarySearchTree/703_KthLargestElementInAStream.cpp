#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class KthLargest
{
    int K;
    priority_queue<int, vector<int>, greater<int>> heap;

public:
    KthLargest(int k, vector<int> &nums)
    {
        K = k;
        for (int n : nums)
            add(n);
    }
    int add(int val)
    {
        heap.push(val);
        if (heap.size() > K)
            heap.pop();
        return heap.top();
    }
};