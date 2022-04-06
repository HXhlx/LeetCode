#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int x = 0;
        for (int k = 30; k >= 0; --k)
        {
            unordered_set<int> seen;
            for (int num : nums)
                seen.insert(num >> k);
            int x_next = x * 2 + 1;
            bool found = false;
            for (int num : nums)
                if (seen.find(x_next ^ (num >> k)) != seen.end())
                {
                    found = true;
                    break;
                }
            x = x_next - !found;
        }
        return x;
    }
};