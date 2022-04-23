#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    }
};