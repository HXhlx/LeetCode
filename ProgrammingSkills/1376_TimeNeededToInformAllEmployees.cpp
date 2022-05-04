#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
    int nom = 0;
    unsigned n;
    vector<int> himn;
    void DFS(unsigned c, vector<int> &manager, vector<int> &informTime)
    {
        if (manager[c] != -1 && himn[manager[c]] == 0)
            DFS(manager[c], manager, informTime);
        nom = max(himn[c] += informTime[c] + (manager[c] == -1 ? 0 : himn[manager[c]]), nom);
    }

  public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        n = manager.size();
        himn.resize(n);
        for (unsigned im = 0; im < n; ++im)
            if (!informTime[im])
                DFS(im, manager, informTime);
        return nom;
    }
};