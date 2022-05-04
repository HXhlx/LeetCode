#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        while (s.back() == ' ')
            s.pop_back();
        return s.length() - (s.rfind(' ') + 1ull);
    }
};