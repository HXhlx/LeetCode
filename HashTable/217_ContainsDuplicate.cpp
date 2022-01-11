#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> f;
        for (int &i : nums)
        {
            if (f.find(i) != f.end())
                return true;
            f.insert(i);
        }
        return false;
    }
};
TEST(ContainsDuplicate, 1)
{
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    EXPECT_TRUE(s.containsDuplicate(nums));
}