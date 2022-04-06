#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        auto [f, l] = equal_range(nums.begin(), nums.end(), target);
        return f == l ? vector<int>{EOF, EOF} : vector<int>{static_cast<int>(distance(nums.begin(), f)), static_cast<int>(distance(nums.begin(), l) - 1)};
    }
};