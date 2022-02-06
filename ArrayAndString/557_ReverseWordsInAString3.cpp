#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
  public:
    string reverseWords(string s)
    {
        for (string::iterator a = s.begin(), b = s.begin(); b != s.end() + 1; ++b)
            if (b != s.end() && *b == ' ' || b == s.end())
            {
                reverse(a, b);
                a = b + 1;
            }
        return s;
    }
};