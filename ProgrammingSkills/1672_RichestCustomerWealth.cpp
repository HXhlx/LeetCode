#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int mw = accumulate(accounts[0].begin(), accounts[0].end(), 0);
        for_each(accounts.begin() + 1, accounts.end(), [&mw](vector<int> &account)
                 { mw = max(mw, accumulate(account.begin(), account.end(), 0)); });
        return mw;
    }
};