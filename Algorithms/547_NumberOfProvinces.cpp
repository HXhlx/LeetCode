#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    wint_t provinces;
    bitset<200> visited;
    void dfs(vector<vector<int>> &isConnected, wint_t i)
    {
        for (wint_t j = 0; j < provinces; ++j)
            if (!visited[j] && isConnected[i][j])
            {
                visited.set(j);
                dfs(isConnected, j);
            }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        provinces = isConnected.size();
        int p = 0;
        for (wint_t i = 0; i < provinces; ++i)
            if (!visited[i])
            {
                dfs(isConnected, i);
                ++p;
            }
        return p;
    }
};