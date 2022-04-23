#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class NumArray
{
    vector<int> sums;

public:
    NumArray(vector<int> &nums)
    {
        sums.resize(nums.size());
        partial_sum(nums.begin(), nums.end(), sums.begin());
    }
    int sumRange(int left, int right)
    {
        return sums[right] - (left ? sums[left - 1] : 0);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */