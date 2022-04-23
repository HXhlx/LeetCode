#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<array<char, 26>, vector<string>> groups;
        for (string &str : strs)
        {
            array<char, 26> frequent{};
            for (char c : str)
                ++frequent[c - 'a'];
            groups[frequent].emplace_back(str);
        }
        vector<vector<string>> ret;
        for (const pair<array<char, 26>, vector<string>> &group : groups)
            ret.emplace_back(group.second);
        return ret;
    }
};