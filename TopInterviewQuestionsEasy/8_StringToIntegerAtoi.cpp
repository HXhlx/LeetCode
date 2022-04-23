#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        try
        {
            return stoi(s);
        }
        catch (out_of_range &e)
        {
            return s.find('-') == string::npos ? INT_MAX : INT_MIN;
        }
        catch (invalid_argument &e)
        {
            return 0;
        }
    }
};