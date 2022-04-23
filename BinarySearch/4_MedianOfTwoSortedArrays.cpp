#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int s1 = nums1.size(), s2 = nums2.size(), l = 0, r = s1, m1 = 0, m2 = 0;
        while (l <= r)
        {
            int i = (l + r) >> 1, j = (s1 + s2 + 1) / 2 - i, ni1 = i ? nums1[i - 1] : INT_MIN, ni = i == s1 ? INT_MAX : nums1[i], nj1 = j ? nums2[j - 1] : INT_MIN, nj = j == s2 ? INT_MAX : nums2[j];
            if (ni1 <= nj)
            {
                m1 = max(ni1, nj1);
                m2 = min(ni, nj);
                l = i + 1;
            }
            else
                r = i - 1;
        }
        return (s1 + s2) % 2 ? m1 : double(m1 + m2) / 2;
    }
};