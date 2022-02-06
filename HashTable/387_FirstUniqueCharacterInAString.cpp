#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.size();
        array<int, 26> abc{};
        abc.fill(n + 1);
        for (int i = 0; i < n; ++i)
        {
            int k = s[i] - 'a';
            abc[k] = abc[k] <= n ? n : i;
        }
        int first = *min_element(abc.begin(), abc.end());
        return first >= n ? -1 : first;
    }
};
TEST(FirstUniqueCharacterInAString, 1)
{
    Solution s;
    EXPECT_EQ(s.firstUniqChar("leetcode"), 0);
}
TEST(FirstUniqueCharacterInAString, 2)
{
    Solution s;
    EXPECT_EQ(s.firstUniqChar("loveleetcode"), 2);
}
TEST(FirstUniqueCharacterInAString, 3)
{
    Solution s;
    EXPECT_EQ(s.firstUniqChar("aabb"), -1);
}