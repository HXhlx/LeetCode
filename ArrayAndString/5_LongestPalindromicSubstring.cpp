#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    int n;
    int expand(string &s, int l, int r)
    {
        while (l >= 0 && r < n && s[l] == s[r])
        {
            --l;
            ++r;
        }
        return (r - l - 2) / 2;
    }

public:
    string longestPalindrome(string s)
    {
        int start = 0, end = -1;
        string t = "#";
        vector<int> arm_len;
        for (char c : s)
        {
            t += c;
            t += '#';
        }
        t += '#';
        s = t;
        t.clear();
        n = s.size();
        for (int i = 0, r = -1, j = -1; i < n; ++i)
        {
            int min_arm_len = r >= i ? min(arm_len[j * 2 - i], r - i) : 0;
            int cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
            arm_len.emplace_back(cur_arm_len);
            if (i + cur_arm_len > r)
            {
                j = i;
                r = i + cur_arm_len;
            }
            if (cur_arm_len * 2 + 1 > end - start)
            {
                start = i - cur_arm_len;
                end = i + cur_arm_len;
            }
        }
        for (int i = start; i <= end; ++i)
            if (s[i] != '#')
                t += s[i];
        return t;
    }
};