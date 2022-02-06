#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        if (mat.empty())
            return mat;
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c)
            return mat;
        vector<vector<int>> Mat;
        for (int i = 0; i < r; ++i)
        {
            vector<int> M;
            for (int j = 0; j < c; ++j)
            {
                int k = i * c + j;
                M.push_back(mat[k / n][k % n]);
            }
            Mat.push_back(M);
        }
        return Mat;
    }
};