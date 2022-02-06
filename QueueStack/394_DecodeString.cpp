#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    string decodeString(string s)
    {
        stack<wint_t> nums;
        stack<string> strs;
        string res;
        for (string::iterator i = s.begin(); i != s.end();)
        {
            string str, ss;
            switch (*i)
            {
            case '[':
                strs.emplace("");
                break;
            case ']':
                str = strs.top();
                for (wint_t j = 0, n = nums.top(); j < n; ++j)
                    ss += str;
                nums.pop();
                strs.pop();
                if (strs.empty())
                    res += ss;
                else
                    strs.top() += ss;
                break;
            default:
                for (string::iterator j = i; j != s.end() && isalpha(*j); ++j)
                    str += *j;
                for (string::iterator j = i; j != s.end() && isdigit(*j); ++j)
                    str += *j;
                if (isalpha(*i))
                    if (strs.empty())
                        res += str;
                    else
                        strs.top() += str;
                else if (isdigit(*i))
                    nums.emplace(stoi(str));
                break;
            }
            advance(i, *i == '[' || *i == ']' ? 1 : str.length());
        }
        return res;
    }
};