#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        return (s + s).find(s, 1) != s.length();
    }
};