#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int sn = n * n;
        vector<vector<int>> genera(n, vector<int>(n));
        array<pair<int, int>, 4> direct = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};
        for (int i = 1, col = 0, row = 0, index = 0; i <= sn; ++i)
        {
            genera[row][col] = i;
            pair<int, int> Next(row + direct[index].first, col + direct[index].second);
            if (Next.first >= n || Next.first < 0 || Next.second >= n || Next.second < 0 || genera[Next.first][Next.second])
                index = (index + 1) % 4;
            row += direct[index].first;
            col += direct[index].second;
        }
        return genera;
    }
};