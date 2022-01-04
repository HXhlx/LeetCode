#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> order;
        order.reserve(m * n);
        for (int i = 1; i < m + n; ++i)
            switch (i % 2)
            {
            case 0:
                for (int c = min(i - 1, n - 1), r = i - c - 1, mr = min(i, m); r < mr; ++r, --c)
                    order.emplace_back(mat[r][c]);
                break;
            case 1:
                for (int r = min(i - 1, m - 1), c = i - r - 1, mc = min(i, n); c < mc; --r, ++c)
                    order.emplace_back(mat[r][c]);
                break;
            }
        return order;
    }
};