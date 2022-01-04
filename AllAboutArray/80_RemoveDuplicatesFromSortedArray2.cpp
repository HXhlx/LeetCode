#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        vector<int>::iterator slow = nums.begin(), fast = nums.begin();
        while (fast != nums.end())
        {
            int c = 0;
            while (fast != nums.end() && *fast == *slow)
            {
                ++c;
                ++fast;
            }
            if (c > 1)
            {
                *(slow + 1) = *slow;
                slow += 2;
            }
            else
                ++slow;
            if (fast != nums.end())
                *slow = *fast;
        }
        return distance(nums.begin(), slow);
    }
};