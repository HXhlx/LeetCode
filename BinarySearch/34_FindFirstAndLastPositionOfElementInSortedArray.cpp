#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size(), pre = -1, post = n;
        for (int low = 0, high = n - 1; low <= high;)
        {
            int mid = (low + high) >> 1;
            if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid - 1;
            else
            {
                pre = post = mid;
                break;
            }
        }
        while (pre - 1 >= 0 && nums[pre - 1] == nums[pre])
            --pre;
        while (post + 1 < n && nums[post + 1] == nums[post])
            ++post;
        return {pre, post == n ? -1 : post};
    }
};