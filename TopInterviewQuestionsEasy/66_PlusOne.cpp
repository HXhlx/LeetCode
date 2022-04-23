#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int>::reverse_iterator it = digits.rbegin();
        while (it != digits.rend() && *it == 9)
            *it++ = 0;
        if (it != digits.rend())
            ++*it;
        else
            digits.insert(digits.begin(), 1);
        return digits;
    }
};