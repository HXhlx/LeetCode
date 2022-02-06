#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int add = 0;
        string ans = "";
        for (string::reverse_iterator n1 = num1.rbegin(), n2 = num2.rbegin(); n1 != num1.rend() || n2 != num2.rend() || add;)
        {
            int result = (n1 != num1.rend() ? *n1++ - '0' : 0) + (n2 != num2.rend() ? *n2++ - '0' : 0) + add;
            ans.push_back(result % 10 + '0');
            add = result / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};