#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        auto cmp = [](pair<int, int> &m, pair<int, int> &n)
        { return m.second > n.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        unordered_map<int, int> occurrences;
        vector<int> ret;
        for (int n : nums)
            ++occurrences[n];
        for (auto &[n, c] : occurrences)
            if (q.size() == k)
            {
                if (q.top().second < c)
                {
                    q.pop();
                    q.emplace(n, c);
                }
            }
            else
                q.emplace(n, c);
        while (!q.empty())
        {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};
TEST(TopKFrequentElements, 1)
{
    int k = 2;
    Solution s;
    vector<int> nums{1, 1, 1, 2, 2, 3}, ans{1, 2}, res = s.topKFrequent(nums, k);
    ASSERT_EQ(ans.size(), res.size());
    for (wint_t i = 0; i < res.size(); ++i)
        EXPECT_EQ(ans[i], res[i]);
}