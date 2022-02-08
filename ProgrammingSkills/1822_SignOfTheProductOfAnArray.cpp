#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int p = 1;
        for (int &n : nums)
            if (n < 0)
                p = -p;
            else if (n == 0)
                return 0;
        return p;
    }
};