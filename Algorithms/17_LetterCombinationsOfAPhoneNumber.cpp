#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    string letter;
    string::iterator end;
    vector<string> letters;
    unordered_map<char, string> phones = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    void DFS(string::iterator it)
    {
        if (it == end)
        {
            if (!letter.empty())
                letters.emplace_back(letter);
            return;
        }
        for (char c : phones[*it])
        {
            letter.push_back(c);
            DFS(it + 1);
            letter.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        end = digits.end();
        DFS(digits.begin());
        return letters;
    }
};