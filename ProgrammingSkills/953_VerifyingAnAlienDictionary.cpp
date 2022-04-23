#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        array<wint_t, 26> order_map;
        for (wint_t i = 0; i < 26; ++i)
            order_map[order[i] - 'a'] = i;
        for (vector<string>::iterator it = words.begin() + 1; it != words.end(); ++it)
        {
            wint_t k = 0, n = min(it->length(), (it - 1)->length());
            while (k < n)
            {
                if (order_map[it->at(k) - 'a'] > order_map[(it - 1)->at(k) - 'a'])
                    break;
                else if (order_map[it->at(k) - 'a'] < order_map[(it - 1)->at(k) - 'a'])
                    return false;
                ++k;
            }
            if (k == n && (it - 1)->length() != n && it->length() == n)
                return false;
        }
        return true;
    }
};
TEST(VerifyingAnAlienDictionary, 1)
{
    Solution s;
    vector<string> words{"hello", "leetcode"};
    EXPECT_TRUE(s.isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz"));
}
TEST(VerifyingAnAlienDictionary, 2)
{
    Solution s;
    vector<string> words{"word", "world", "row"};
    EXPECT_FALSE(s.isAlienSorted(words, "worldabcefghijkmnpqstuvxyz"));
}
TEST(VerifyingAnAlienDictionary, 3)
{
    Solution s;
    vector<string> words{"apple", "app"};
    EXPECT_FALSE(s.isAlienSorted(words, "abcdefghijklmnopqrstuvwxyz"));
}