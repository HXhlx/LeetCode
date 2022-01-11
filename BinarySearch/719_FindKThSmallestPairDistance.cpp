#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int l = 0, h = nums.back() - nums.front();
        while (l < h)
        {
            int m = (l + h) >> 1, c = 0;
            for (vector<int>::iterator L = nums.begin(), R = nums.begin(); R != nums.end(); ++R)
            {
                while (*R - *L > m)
                    ++L;
                c += distance(L, R);
            }
            if (c >= k)
                h = m;
            else
                l = m + 1;
        }
        return l;
    }
};