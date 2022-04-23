#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int p0 = 0, p2 = nums.size() - 1;
        for (int i = 0; i <= p2; ++i)
        {
            while (i <= p2 && nums[i] == 2)
            {
                nums[i] = nums[p2];
                nums[p2--] = 2;
            }
            if (nums[i] == 0)
            {
                nums[i] = nums[p0];
                nums[p0++] = 0;
            }
        }
    }
};