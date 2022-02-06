#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int countOdds(int low, int high)
    {
        return (high + 1) / 2 - low / 2;
    }
};