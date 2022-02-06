#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int s = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it += 2)
            s += *it;
        return s;
    }
};