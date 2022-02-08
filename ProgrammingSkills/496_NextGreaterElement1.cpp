#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> ids;
        stack<int> nums;
        vector<int> nge(nums1.size());
        for (vector<int>::reverse_iterator it = nums2.rbegin(); it != nums2.rend(); ++it)
        {
            while (!nums.empty() && *it >= nums.top())
                nums.pop();
            ids[*it] = nums.empty() ? -1 : nums.top();
            nums.emplace(*it);
        }
        for (wint_t i = 0, n = nums1.size(); i < n; ++i)
            nge[i] = ids[nums1[i]];
        return nge;
    }
};
TEST(NextGreaterElement1, 1)
{
    Solution s;
    vector<int> nums1{4, 1, 2}, nums2{1, 3, 4, 2}, nge{-1, 3, -1}, ans = s.nextGreaterElement(nums1, nums2);
    ASSERT_EQ(nge.size(), ans.size());
    EXPECT_TRUE(equal(nge.begin(), nge.end(), ans.begin()));
}
TEST(NextGreaterElement1, 2)
{
    Solution s;
    vector<int> nums1{2, 4}, nums2{1, 2, 3, 4}, nge{3, -1}, ans = s.nextGreaterElement(nums1, nums2);
    ASSERT_EQ(nge.size(), ans.size());
    EXPECT_TRUE(equal(nge.begin(), nge.end(), ans.begin()));
}