#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> roman2int = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        for (string::iterator it = s.begin(); it != s.end(); ++it)
            sum += (it + 1 != s.end() && roman2int[*it] < roman2int[*(it + 1)] ? -1 : 1) * roman2int[*it];
        return sum;
    }
};