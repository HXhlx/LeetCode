#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string word;
        wint_t w = 0;
        for (wint_t ma = min(word1.length(), word2.length()); w < ma; ++w)
        {
            word += word1[w];
            word += word2[w];
        }
        return word + (word1.length() > word2.length() ? word1.substr(w) : word2.substr(w));
    }
};