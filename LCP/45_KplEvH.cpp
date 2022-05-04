#include <bits/stdc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
    array<pair<short, short>, 4> s{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};
    set<vector<int>> by;
    vector<vector<unordered_set<wint_t>>> opt;
    wint_t m, n;
    void DFS(vector<int> &position, vector<vector<int>> &terrain, vector<vector<int>> &obstacle, int v)
    {
        if (v < 1)
            return;
        if (v == 1)
            by.emplace(position);
        for (pair<short, short> &as : s)
        {
            vector<int> p{position.front() + as.first, position.back() + as.second};
            if (p.front() >= 0 && p.front() < n && p.back() >= 0 && p.back() < m)
            {
                v += terrain[position.front()][position.back()] - terrain[p.front()][p.back()] - obstacle[p.front()][p.back()];
                if (opt[p.front()][p.back()].find(v) != opt[p.front()][p.back()].end())
                    return;
                opt[p.front()][p.back()].emplace(v);
                DFS(p, terrain, obstacle, v);
                opt[p.front()][p.back()].emplace(v);
            }
        }
    }

public:
    vector<vector<int>> bicycleYard(vector<int> &position, vector<vector<int>> &terrain, vector<vector<int>> &obstacle)
    {
        m = terrain.front().size();
        n = terrain.size();
        opt = vector<vector<unordered_set<wint_t>>>(n, vector<unordered_set<wint_t>>(m));
        DFS(position, terrain, obstacle, 1);
        by.erase(position);
        return vector<vector<int>>(by.begin(), by.end());
    }
};
TEST(KplEvH, 1)
{
    Solution s;
    vector<int> position{0, 0};
    vector<vector<int>> terrain{{0, 0}, {0, 0}}, obstacle{{0, 0}, {0, 0}}, by = s.bicycleYard(position, terrain, obstacle), opt{{0, 1}, {1, 0}, {1, 1}};
    EXPECT_EQ(by, opt);
}
TEST(KplEvH, 2)
{
    Solution s;
    vector<int> position{1, 1};
    vector<vector<int>> terrain{{5, 0}, {0, 6}}, obstacle{{0, 6}, {7, 0}}, by = s.bicycleYard(position, terrain, obstacle), opt{{0, 1}};
    EXPECT_EQ(by, opt);
}