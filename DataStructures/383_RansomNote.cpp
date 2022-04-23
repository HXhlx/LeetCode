#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        array<int, 26> abc{};
        for (char c : magazine)
            ++abc[c - 'a'];
        for (char c : ransomNote)
            if (--abc[c - 'a'] < 0)
                return false;
        return true;
    }
};