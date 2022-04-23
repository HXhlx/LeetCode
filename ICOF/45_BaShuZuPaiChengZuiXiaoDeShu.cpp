#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution {
public:
    string minNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), [](int& a, int& b) {
            string A = to_string(a), B = to_string(b);
            return A + B < B + A;
        });
        return accumulate(nums.begin(), nums.end(), string(""), [](const string& s, int& n) { return s + to_string(n); });
    }
};