#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> nums;
        for_each(tokens.begin(), tokens.end(), [&nums](string &str)
                 {
                     try
                     {
                         nums.emplace(stoi(str));
                     }
                     catch (const invalid_argument &e)
                     {
                         int n1 = nums.top();
                         nums.pop();
                         int n2 = nums.top();
                         nums.pop();
                         switch (str.front())
                         {
                         case '+':
                             nums.emplace(n1 + n2);
                             break;
                         case '-':
                             nums.emplace(n2 - n1);
                             break;
                         case '*':
                             nums.emplace(n1 * n2);
                             break;
                         case '/':
                             nums.emplace(n2 / n1);
                             break;
                         }
                     }
                 });
        return nums.top();
    }
};