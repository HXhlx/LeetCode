#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    int m, n;
    void DFS(vector<vector<char>> &board, int x, int y)
    {
        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O')
        {
            board[x][y] = 'o';
            DFS(board, x - 1, y);
            DFS(board, x, y - 1);
            DFS(board, x + 1, y);
            DFS(board, x, y + 1);
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        if (m == 0)
            return;
        n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            DFS(board, i, 0);
            DFS(board, i, n - 1);
        }
        for (int i = 1; i < n - 1; ++i)
        {
            DFS(board, 0, i);
            DFS(board, m - 1, i);
        }
        for (vector<char> &line : board)
            for (char &c : line)
                switch (c)
                {
                case 'O':
                    c = 'X';
                    break;
                case 'o':
                    c = 'O';
                    break;
                }
    }
};