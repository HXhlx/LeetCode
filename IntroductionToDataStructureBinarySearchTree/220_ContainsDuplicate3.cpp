#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
    long getID(long x, long w)
    {
        return x < 0 ? (x + 1ll) / w - 1 : x / w;
    }

public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        unordered_map<long, long> mp;
        for (long i = 0, n = nums.size(); i < n; ++i)
        {
            long x = nums[i], id = getID(x, (long)t + 1);
            if (mp.find(id) != mp.end() || mp.find(id - 1) != mp.end() && abs(x - mp[id - 1]) <= t || mp.find(id + 1) != mp.end() && abs(x - mp[id + 1]) <= t)
                return true;
            mp[id] = x;
            if (i >= k)
                mp.erase(getID(nums[i - k], (long)t + 1));
        }
        return false;
    }
};