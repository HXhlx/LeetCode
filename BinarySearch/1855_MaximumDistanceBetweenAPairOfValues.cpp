#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int md = 0;
        for (wint_t i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size(); i < n1; ++i)
        {
            j = max(i + 1u, static_cast<unsigned>(distance(nums2.begin(), find_if(nums2.begin() + j, nums2.end(), [i, &nums1](int n)
                                                                                  { return nums1[i] > n; }))));
            md = max(static_cast<unsigned>(md), j - i - 1u);
        }
        return md;
    }
};