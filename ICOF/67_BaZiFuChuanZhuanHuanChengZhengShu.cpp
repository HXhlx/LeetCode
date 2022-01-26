#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int strToInt(string str)
    {
        try
        {
            return stoi(str);
        }
        catch (out_of_range &e)
        {
            return str.find('-') == string::npos ? INT_MAX : INT_MIN;
        }
        catch (invalid_argument &e)
        {
            return 0;
        }
    }
};