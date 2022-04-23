#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int p = 0;
        if (points.size() <= 2)
            return points.size();
        for (vector<vector<int>>::iterator a = points.begin(); a != points.end() && p <= min(distance(a, points.end()) + 1, (long)points.size()); ++a)
        {
            map<pair<int, int>, int> lines;
            for (vector<vector<int>>::iterator b = a + 1; b != points.end(); ++b)
            {
                int x = a->front() - b->front(), y = a->back() - b->back();
                if (x == 0)
                    y = 1;
                else if (y == 0)
                    x = 1;
                else
                {
                    if (y < 0)
                    {
                        x = -x;
                        y = -y;
                    }
                    int g = gcd(x, y);
                    x /= g;
                    y /= g;
                }
                ++lines[{x, y}];
            }
            if (!lines.empty())
                p = max(p, max_element(lines.begin(), lines.end(), [](const pair<pair<int, int>, int> &A, const pair<pair<int, int>, int> &B)
                                       { return A.second < B.second; })
                                   ->second +
                               1);
        }
        return p;
    }
};
TEST(MaxPointsOnALine, 2)
{
    Solution s;
    vector<vector<int>> points{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    EXPECT_EQ(s.maxPoints(points), 4);
}
TEST(MaxPointsOnALine, 3)
{
    Solution s;
    vector<vector<int>> points{{0, 0}, {1, -1}, {1, 1}};
    EXPECT_EQ(s.maxPoints(points), 2);
}