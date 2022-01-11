#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    unique_ptr<bool[]> visited;
    void DFS(vector<vector<int>> &rooms, int idx)
    {
        for (int i : rooms[idx])
            if (!visited[i])
            {
                visited[i] = true;
                DFS(rooms, i);
            }
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        wint_t n = rooms.size();
        visited.reset(new bool[n]());
        visited[0] = true;
        DFS(rooms, 0);
        return accumulate(visited.get(), visited.get() + n, true, bit_and());
    }
};