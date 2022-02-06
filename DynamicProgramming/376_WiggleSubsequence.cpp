#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        int d = 0, wml = 1;
        vector<int>::iterator it = nums.begin() + 1;
        while (d == 0 && it != nums.end())
        {
            d = *it - *(it - 1);
            ++it;
        }
        if (d)
            ++wml;
        while (it != nums.end())
        {
            int D = *it - *(it - 1);
            if (D * d < 0)
                ++wml;
            if (D)
                d = D;
            ++it;
        }
        return wml;
    }
};