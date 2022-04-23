#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        bitset<52> alpha;
        for (char c : jewels)
            alpha.set(c - (isupper(c) ? 39 : 97));
        return count_if(stones.begin(), stones.end(), [&alpha](char c)
                        { return alpha[c - (isupper(c) ? 39 : 97)]; });
    }
};