#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        size_t len = s.size();
        if(len!=t.size())
            return false;
        array<int, 26> abc{};
        for (size_t i = 0; i < len;++i){
            ++abc[t[i] - 'a'];
            --abc[s[i] - 'a'];
        }
        return *max_element(abc.begin(), abc.end()) == 0;
    }
};