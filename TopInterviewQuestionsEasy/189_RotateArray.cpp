#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        ::rotate(nums.begin(), nums.end() - k % nums.size(), nums.end());
    }
};