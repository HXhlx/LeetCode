#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 20000));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 0)
                    dist[i][j] = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (i >= 1)
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                if (j >= 1)
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
            }
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j)
            {
                if (i + 1 < m)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j + 1 < n)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        return dist;
    }
};
TEST(Matrix, 3)
{
    Solution s;
    vector<vector<int>> mat = {{0}, {0}, {0}, {0}, {0}}, dist = s.updateMatrix(mat);
    for (int m = 0; m < 5; ++m)
        for (int n = 0; n < 1; ++n)
            EXPECT_EQ(mat[m][n], dist[m][n]);
}