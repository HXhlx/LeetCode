#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int minCount(vector<int> &coins)
    {
        int mc = 0;
        for (int &c : coins)
            mc += c / 2 + c % 2;
        return mc;
    }
};