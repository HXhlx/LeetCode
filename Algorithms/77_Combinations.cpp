#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> combination(k + 1);
        vector<vector<int>> combinations;
        iota(combination.begin(), combination.end() - 1, 1);
        combination.back() = n + 1;
        for (int j = 0; j < k; ++combination[j])
        {
            combinations.emplace_back(combination.begin(), combination.end() - 1);
            for (j = 0; j < k && combination[j] + 1 == combination[j + 1]; ++j)
                combination[j] = j + 1;
        }
        return combinations;
    }
};