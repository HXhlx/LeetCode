#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
struct Node
{
    array<Node *, 2> sub_nodes{};
    int m = INT_MAX;
};
class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        const wint_t L = 30;
        Node *root = new Node;
        unsigned n = queries.size();
        vector<int> anwser(n);
        for (int val : nums)
        {
            Node *node = root;
            node->m = min(node->m, val);
            for (int i = L - 1; i >= 0; --i)
            {
                bool bit = (val >> i) & 1;
                if (!node->sub_nodes[bit])
                    node->sub_nodes[bit] = new Node;
                node = node->sub_nodes[bit];
                node->m = min(node->m, val);
            }
        }
        for (unsigned i = 0; i < n; ++i)
        {
            Node *node = root;
            if (node->m > queries[i][1])
                anwser[i] = -1;
            else
                for (int j = L - 1; j >= 0; --j)
                {
                    bool bit = (queries[i][0] >> j) & 1;
                    if (node->sub_nodes[bit ^ 1] && node->sub_nodes[bit ^ 1]->m <= queries[i][1])
                    {
                        anwser[i] |= 1 << j;
                        bit ^= 1;
                    }
                    node = node->sub_nodes[bit];
                }
        }
        return anwser;
    }
};
TEST(MaximumXorWithAnElementFromArray, 1)
{
    Solution s;
    vector<vector<int>> queries{{3, 1}, {1, 3}, {5, 6}};
    vector<int> nums{0, 1, 2, 3, 4}, ans{3, 3, 7}, res = s.maximizeXor(nums, queries);
    ASSERT_EQ(ans.size(), res.size());
    EXPECT_EQ(ans, res);
}