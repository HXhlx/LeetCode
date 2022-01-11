#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        int c = 0, prod = 1;
        for (vector<int>::iterator a = nums.begin(), b = nums.begin(); b != nums.end(); ++b)
        {
            prod *= *b;
            while (prod >= k)
                prod /= *a++;
            c += distance(a, b) + 1;
        }
        return c;
    }
};