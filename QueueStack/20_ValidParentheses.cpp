#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> parentheses;
        unordered_map<char, char> links = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        for (char c : s)
            if (!parentheses.empty() && links.find(parentheses.top()) != links.end() && links[parentheses.top()] == c)
                parentheses.pop();
            else if (links.find(c) != links.end())
                parentheses.emplace(c);
            else
                return false;
        return parentheses.empty();
    }
};