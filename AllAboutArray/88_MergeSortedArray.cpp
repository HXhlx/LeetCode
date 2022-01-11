#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        while (m > 0 && n > 0)
            nums1[m + n] = nums1[m - 1] <= nums2[n - 1] ? nums2[--n] : nums1[--m];
        while (n-- > 0)
            nums1[n] = nums2[n];
    }
};