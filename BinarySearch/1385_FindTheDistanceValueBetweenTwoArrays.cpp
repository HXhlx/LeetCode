#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int ftdv = arr1.size();
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        for (vector<int>::iterator a1 = arr1.begin(), a2 = arr2.begin(); a1 != arr1.end(); ++a1)
        {
            a2 = find(a2, arr2.end(), *a1);
            if (a2 != arr2.begin() && abs(*a1 - *(a2 - 1)) <= d || a2 != arr2.end() && abs(*a1 - *a2) <= d)
                --ftdv;
        }
        return ftdv;
    }
};
TEST(FindTheDistanceValueBetweenTwoArrays, 1)
{
    Solution s;
    vector<int> arr1{4, 5, 8}, arr2{10, 9, 1, 8};
    EXPECT_EQ(s.findTheDistanceValue(arr1, arr2, 2), 2);
}
TEST(FindTheDistanceValueBetweenTwoArrays, 2)
{
    Solution s;
    vector<int> arr1{1, 4, 2, 3}, arr2{-4, -3, 6, 10, 20, 30};
    EXPECT_EQ(s.findTheDistanceValue(arr1, arr2, 3), 2);
}
TEST(FindTheDistanceValueBetweenTwoArrays, 3)
{
    Solution s;
    vector<int> arr1{2, 1, 100, 3}, arr2{-5, -2, 10, -3, 7};
    EXPECT_EQ(s.findTheDistanceValue(arr1, arr2, 6), 1);
}