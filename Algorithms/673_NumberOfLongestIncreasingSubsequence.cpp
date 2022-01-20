#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    vector<pair<wint_t, wint_t>> tree;
    wint_t n;
    int lowbit(int x)
    {
        return x & -x;
    }
    pair<wint_t, wint_t> query(int x)
    {
        wint_t len = 0, cnt = 0;
        for (int i = x; i; i -= lowbit(i))
            if (len == tree[i].first)
                cnt += tree[i].second;
            else if (len < tree[i].first)
            {
                len = tree[i].first;
                cnt = tree[i].second;
            }
        return {len, cnt};
    }
    void add(int x, pair<wint_t, wint_t> info)
    {
        for (int i = x; i <= n; i += lowbit(i))
        {
            if (tree[i].first == info.first)
                tree[i].second += info.second;
            else if (tree[i].first < info.first)
                tree[i] = info;
        }
    }

public:
    int findNumberOfLIS(vector<int> &nums)
    {
        vector<int> tmp(nums);
        wint_t idx = 0;
        n = nums.size();
        tree.resize(n + 1);
        sort(tmp.begin(), tmp.end());
        unordered_map<int, wint_t> m;
        for (int &num : tmp)
            if (m.find(num) == m.end())
                m[num] = ++idx;
        for (int &num : nums)
        {
            pair<wint_t, wint_t> info = query(m[num] - 1);
            add(m[num], {info.first + 1, max(info.second, (wint_t)1)});
        }
        return query(n).second;
    }
};