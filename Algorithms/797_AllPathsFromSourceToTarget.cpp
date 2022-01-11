#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    int n;
    vector<vector<int>> paths;
    vector<int> path;
    void DFS(vector<vector<int>> &graph, int x)
    {
        if (x == n)
        {
            paths.emplace_back(path);
            return;
        }
        for (int &y : graph[x])
        {
            path.emplace_back(y);
            DFS(graph, y);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        n = graph.size() - 1;
        path.emplace_back(0);
        DFS(graph, 0);
        return paths;
    }
};