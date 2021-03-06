#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; ++i)
            row[i] = 1ll * row[i - 1] * (rowIndex - i + 1) / i;
        return row;
    }
};