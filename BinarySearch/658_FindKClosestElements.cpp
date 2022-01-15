#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int l = 0, h = arr.size() - 1, n = arr.size();
        if (arr.front() >= x)
            return vector<int>(arr.begin(), arr.begin() + k);
        if (arr.back() <= x)
            return vector<int>(arr.end() - k, arr.end());
        while (h - l + 1 > k)
        {
            int m = midpoint(l, h);
            if (arr[m] > x)
                h = m - l + 1 >= k ? m : l + k - 1;
            else if (arr[m] < x)
                l = h - m >= k ? m + 1 : h - k + 1;
            else
            {
                int mk = k >> 1;
                h = m + mk - (k % 2 == 0);
                l = m - mk;
            }
        }
        while (l && x - arr[l - 1] <= arr[h] - x)
        {
            --l;
            --h;
        }
        while (h < n - 1 && x - arr[l] > arr[h + 1] - x)
        {
            ++l;
            ++h;
        }
        return vector<int>(arr.begin() + l, arr.begin() + h + 1);
    }
};
TEST(FindKClosestElements, 1)
{
    Solution s;
    vector<int> arr{1, 2, 3, 4, 5}, res = s.findClosestElements(arr, 4, 3), ans{1, 2, 3, 4};
    ASSERT_EQ(res.size(), ans.size());
    for (wint_t i = 0; i < res.size(); ++i)
        EXPECT_EQ(res[i], ans[i]);
}