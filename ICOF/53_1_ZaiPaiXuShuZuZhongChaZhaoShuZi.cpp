#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return 0;
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            unsigned mid = (low + high) >> 1;
            if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid;
            else
                low = high = mid;
        }
        while (low >= 0 && nums[low] == target)
            --low;
        while (high < nums.size() && nums[high] == target)
            ++high;
        return max(high - low - 1, 0);
    }
};