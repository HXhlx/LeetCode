#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        return accumulate(s.begin(), s.end(), 0, bit_xor<char>()) ^ accumulate(t.begin(), t.end(), 0, bit_xor<char>());
    }
};