#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    string replaceSpace(string s)
    {
        return regex_replace(s, regex(" "), "%20");
    }
};