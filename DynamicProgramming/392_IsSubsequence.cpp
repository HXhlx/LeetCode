#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        string::iterator is = s.begin();
        if (s.empty())
            return true;
        for (string::iterator it = t.begin(); it != t.end(); ++it)
        {
            if (*is == *it)
                if (++is == s.end())
                    return true;
        }
        return false;
    }
};