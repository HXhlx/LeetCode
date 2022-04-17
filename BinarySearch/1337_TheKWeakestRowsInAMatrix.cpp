#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        wint_t m = mat.size(), n = mat.front().size();
        vector<int> kwr(k);
        vector<pair<wint_t, int>> km(m);
        for (wint_t r = 0; r < m; ++r)
            km[r] = {distance(mat[r].begin(), lower_bound(mat[r].begin(), mat[r].end(), 0, greater<>())), r};
        partial_sort(km.begin(), km.begin() + k, km.end());
        for (wint_t r = 0; r < k; ++r)
            kwr[r] = km[r].second;
        return kwr;
    }
};