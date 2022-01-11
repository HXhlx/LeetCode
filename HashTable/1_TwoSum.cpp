#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> difference;
        for (int i = 0; i < nums.size(); ++i)
        {
            unordered_map<int, int>::iterator it = difference.find(target - nums[i]);
            if (it != difference.end())
                return {it->second, i};
            difference[nums[i]] = i;
        }
        return {};
    }
};