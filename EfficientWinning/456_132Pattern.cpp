#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        unsigned n = nums.size();
        stack<int> fp;
        vector<int> pmin { INT_MAX };
        for (unsigned i = 0; i < n; ++i) {
            while (!fp.empty() && nums[fp.top()] <= nums[i])
                fp.pop();
            if (!fp.empty() && pmin[fp.top()] < nums[i])
                return true;
            fp.emplace(i);
            pmin.emplace_back(min(pmin.back(), nums[i]));
        }
        return false;
    }
};