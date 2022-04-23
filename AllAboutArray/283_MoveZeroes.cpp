#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int>::iterator it = nums.begin();
        for (int &n : nums)
            if (n)
                *it++ = n;
        while (it != nums.end())
            *it++ = 0;
    }
};