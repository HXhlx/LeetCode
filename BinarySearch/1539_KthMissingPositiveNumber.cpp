#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        if (arr.front() > k)
            return k;
        wint_t l = 0, h = arr.size();
        while (l < h)
        {
            wint_t m = (l + h) >> 1;
            int x = m < arr.size() ? arr[m] : INT_MAX;
            if (x - m - 1 >= k)
                h = m;
            else
                l = m + 1;
        }
        return k + l;
    }
};