#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = (low + high) >> 1;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low] == target ? low : EOF;
    }
};