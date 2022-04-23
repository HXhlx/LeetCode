#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        for (wint_t c = 0; c < strs[0].length(); ++c)
            for (vector<string>::iterator it = strs.begin() + 1; it != strs.end(); ++it)
                if (c == it->length() || c < it->length() && it->at(c) != (it - 1)->at(c))
                    return it->substr(0, c);
        return strs[0];
    }
};