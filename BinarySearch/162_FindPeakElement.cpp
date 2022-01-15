#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = midpoint(low, high);
            if (nums[mid] < nums[mid + 1])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};