#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        pair<int, int> np(nums[0] > 0, nums[0] < 0);
        int m = np.first;
        for_each(nums.begin() + 1, nums.end(), [&m, &np](int n)
                 {
                     if (n > 0)
                         np = {np.first + 1, (np.second + 1) * (np.second > 0)};
                     else if (n < 0)
                         np = {(np.second + 1) * (np.second > 0), np.first + 1};
                     else
                         np = {};
                     m = max(m, np.first);
                 });
        return m;
    }
};