#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int c = 0, pre = 0;
        for (int &num : nums)
        {
            pre += num;
            if (mp.find(pre - k) != mp.end())
                c += mp[pre - k];
            mp[pre]++;
        }
        return c;
    }
};