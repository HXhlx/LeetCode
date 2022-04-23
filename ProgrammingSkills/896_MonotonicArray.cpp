#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        return is_sorted(nums.begin(), nums.end()) || is_sorted(nums.begin(), nums.end(), greater<>());
    }
};