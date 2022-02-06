#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int low = 0, high = height.size() - 1, s = 0;
        while (low < high)
        {
            s = max(min(height[low], height[high]) * (high - low), s);
            if (height[low] <= height[high])
                ++low;
            else
                --high;
        }
        return s;
    }
};