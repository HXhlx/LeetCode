#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> sums;
        sort(nums.begin(), nums.end());
        if (nums.size() < 4)
            return sums;
        for (wint_t i = 0, n = nums.size(); i < n - 3; ++i)
        {
            if (i && nums[i] == nums[i - 1] || nums[i] + accumulate(nums.end() - 3, nums.end(), 0l) < target)
                continue;
            if (accumulate(nums.begin() + i, nums.begin() + i + 4, 0l) > target)
                break;
            for (wint_t j = i + 1; j < n - 2; ++j)
            {
                if (nums[i] + accumulate(nums.begin() + j, nums.begin() + j + 3, 0l) > target)
                    break;
                if (j > i + 1 && nums[j] == nums[j - 1] || nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
                    continue;
                for (wint_t l = j + 1, r = n - 1; l < r;)
                {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum > target)
                        --r;
                    else if (sum < target)
                        ++l;
                    else
                    {
                        sums.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1])
                            ++l;
                        while (l < r && nums[r] == nums[r - 1])
                            --r;
                        ++l;
                        --r;
                    }
                }
            }
        }
        return sums;
    }
};