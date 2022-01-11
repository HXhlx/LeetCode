#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        istringstream is(s);
        stack<string> strs;
        string str;
        while (is >> str)
            strs.emplace(str);
        str = "";
        while (!strs.empty())
        {
            str += strs.top() + " ";
            strs.pop();
        }
        str.pop_back();
        return str;
    }
};