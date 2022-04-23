#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        long mssp = values[0], m = values[0];
        for (vector<int>::iterator it = values.begin() + 1; it != values.end(); ++it)
        {
            m = max(m, mssp + *it - distance(values.begin(), it));
            mssp = max(mssp, *it + distance(values.begin(), it));
        }
        return m;
    }
};