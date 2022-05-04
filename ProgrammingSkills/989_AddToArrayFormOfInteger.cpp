#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        bool addOne = false;
        vector<int> ataf;
        vector<int>::reverse_iterator in = num.rbegin();
        while (in != num.rend() && k)
        {
            ataf.emplace_back(*in + k % 10 + addOne);
            addOne = ataf.back() / 10;
            ataf.back() -= addOne * 10;
            ++in;
            k /= 10;
        }
        while (in != num.rend())
        {
            ataf.emplace_back(*in + addOne);
            addOne = ataf.back() / 10;
            ataf.back() -= addOne * 10;
            ++in;
        }
        while (k)
        {
            ataf.emplace_back(k % 10 + addOne);
            addOne = ataf.back() / 10;
            ataf.back() -= addOne * 10;
            k /= 10;
        }
        if (addOne)
            ataf.emplace_back(1);
        reverse(ataf.begin(), ataf.end());
        return ataf;
    }
};
TEST(AddToArrayFormOfInteger, 1)
{
    Solution s;
    vector<int> num{1, 2, 0, 0}, ataf{1, 2, 3, 4};
    EXPECT_EQ(s.addToArrayForm(num, 34), ataf);
}
TEST(AddToArrayFormOfInteger, 2)
{
    Solution s;
    vector<int> num{2, 7, 4}, ataf{4, 5, 5};
    EXPECT_EQ(s.addToArrayForm(num, 181), ataf);
}
TEST(AddToArrayFormOfInteger, 3)
{
    Solution s;
    vector<int> num{2, 1, 5}, ataf{1, 0, 2, 1};
    EXPECT_EQ(s.addToArrayForm(num, 806), ataf);
}