#include "gtest/gtest.h"
#include <bits/extc++.h>
using namespace std;
class Solution
{
  public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        wint_t m = l.size();
        vector<bool> cas(m, true);
        for (wint_t k = 0; k < m; ++k)
        {
            vector<int> lnr(r[k] - l[k] + 1);
            partial_sort_copy(nums.begin() + l[k], nums.begin() + r[k] + 1, lnr.begin(), lnr.end());
            for (int d = lnr[1] - lnr[0], i = 1; i < lnr.size(); ++i)
                if (d != lnr[i] - lnr[i - 1])
                {
                    cas[k] = false;
                    break;
                }
        }
        return cas;
    }
};