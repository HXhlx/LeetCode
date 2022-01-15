#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = midpoint(low, high);
            if (nums[mid] < nums[high])
                high = mid;
            else if (nums[mid] > nums[high])
                low = mid + 1;
            else
            {
                while (high > mid && nums[high] == nums[mid])
                    --high;
                while (low < mid && nums[low] == nums[mid])
                    ++low;
            }
        }
        return nums[low];
    }
};