#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = (low + high) >> 1;
            if (nums[mid] < nums[low])
                high = mid;
            else if (nums[mid] > nums[high])
                low = mid + 1;
            else
                break;
        }
        return nums[low];
    }
};