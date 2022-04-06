#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int sols = 0;
        for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
        {
            wint_t l = distance(arr.begin(), it), r = distance(it, arr.end()) - 1;
            sols += *it * (((l + 1) >> 1) * ((r + 1) >> 1) + (l / 2 + 1) * (r / 2 + 1));
        }
        return sols;
    }
};