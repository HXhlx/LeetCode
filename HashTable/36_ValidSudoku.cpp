#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool rows[9][9], cols[9][9], boxes[3][3][9];
        memset(rows, false, 81);
        memset(cols, false, 81);
        memset(boxes, false, 81);
        for (wint_t i = 0; i < 9; ++i)
            for (wint_t j = 0; j < 9; ++j)
            {
                char c = board[i][j];
                if (c != '.')
                {
                    wint_t n = c - '0' - 1;
                    if (rows[i][n] || cols[j][n] || boxes[i / 3][j / 3][n])
                        return false;
                    rows[i][n] = cols[j][n] = boxes[i / 3][j / 3][n] = true;
                }
            }
        return true;
    }
};