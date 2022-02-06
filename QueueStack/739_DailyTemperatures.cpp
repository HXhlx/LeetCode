#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> ids;
        ids.emplace(0);
        vector<int> raise(n, 0);
        for (int i = 1; i < n; ++i)
        {
            while (!ids.empty() && temperatures[ids.top()] < temperatures[i])
            {
                raise[ids.top()] = i - ids.top();
                ids.pop();
            }
            ids.emplace(i);
        }
        return raise;
    }
};