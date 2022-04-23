#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    double average(vector<int> &salary)
    {
        int s = accumulate(salary.begin(), salary.end(), 0), n = salary.size() - 2;
        pair<vector<int>::iterator, vector<int>::iterator> m = minmax_element(salary.begin(), salary.end());
        return double(s - *m.first - *m.second) / n;
    }
};