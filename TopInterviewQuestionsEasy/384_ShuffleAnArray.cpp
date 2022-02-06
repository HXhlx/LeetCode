#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    vector<int> ans;
    default_random_engine dre;

public:
    Solution(vector<int> &nums)
    {
        ans = nums;
    }
    vector<int> reset()
    {
        return ans;
    }
    vector<int> shuffle()
    {
        vector<int> c = ans;
        ::shuffle(c.begin(), c.end(), dre);
        return c;
    }
};