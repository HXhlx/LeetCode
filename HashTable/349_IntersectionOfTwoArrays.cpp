#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s1, s2;
        for (int n : nums1)
            s1.insert(n);
        for (int n : nums2)
            s2.insert(n);
        if (s1.size() > s2.size())
            swap(s1, s2);
        vector<int> inter;
        for (int n : s1)
            if (s2.find(n) != s2.end())
                inter.emplace_back(n);
        return inter;
    }
};