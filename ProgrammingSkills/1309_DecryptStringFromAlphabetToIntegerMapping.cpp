#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    string freqAlphabets(string s)
    {
        string alphas("#abcdefghijklmnopqrstuvwxyz"), fa;
        for (wint_t i = 0, n = s.length(); i < n; ++i)
        {
            if (i + 2 < n && s[i + 2] == '#')
            {
                fa += alphas[stoi(s.substr(i, 2))];
                i += 2;
            }
            else
                fa += alphas[s[i] - '0'];
        }
        return fa;
    }
};