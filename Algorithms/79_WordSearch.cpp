#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    int m, n;
    array<pair<int, int>, 4> direct{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};
    string::iterator end;
    bool DFS(vector<vector<char>> &board, vector<vector<bool>> &visited, int r, int c, string::iterator it)
    {
        bool flag = false;
        if (it + 1 == end)
            return true;
        visited[r][c] = true;
        for (pair<int, int> &d : direct)
        {
            int nr = r + d.first, nc = c + d.second;
            if (nr >= 0 && nc >= 0 && nr < m && nc < n && !visited[nr][nc] && *(it + 1) == board[nr][nc])
                flag |= DFS(board, visited, nr, nc, it + 1);
        }
        visited[r][c] = false;
        return flag;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        end = word.end();
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (board[r][c] == word.front() && DFS(board, visited, r, c, word.begin()))
                    return true;
        return false;
    }
};