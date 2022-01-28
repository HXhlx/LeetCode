#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int V = 0, lm = 0, rm = 0;
        for (unsigned l = 0, r = height.size() - 1; l < r;)
        {
            lm = max(lm, height[l]);
            rm = max(rm, height[r]);
            if (height[l] < height[r])
            {
                V += lm - height[l];
                ++l;
            }
            else
            {
                V += rm - height[r];
                --r;
            }
        }
        return V;
    }
};