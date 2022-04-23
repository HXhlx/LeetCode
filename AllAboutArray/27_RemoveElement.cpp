#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        for (vector<int>::iterator b = nums.begin(); b != nums.end();)
            if (*b == val)
            {
                swap(*b, nums.back());
                nums.pop_back();
            }
            else
                ++b;
        return nums.size();
    }
};