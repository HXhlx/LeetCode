#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> permutations;
        do
            permutations.emplace_back(nums);
        while (next_permutation(nums.begin(), nums.end()));
        return permutations;
    }
};