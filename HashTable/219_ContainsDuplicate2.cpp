#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, wint_t> ids;
        for (wint_t i = 0, n = nums.size(); i < n; ++i)
        {
            if (ids.find(nums[i]) == ids.end())
                ids[nums[i]] = i;
            else if (i - ids[nums[i]] <= k)
                return true;
            else
                ids[nums[i]] = i;
        }
        return false;
    }
};