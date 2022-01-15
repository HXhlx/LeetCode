#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        for (int i = 0, j = numbers.size() - 1; i < j;)
        {
            int m = midpoint(i, j);
            if (numbers[i] + numbers[m] > target)
                j = m - 1;
            else if (numbers[m] + numbers[j] < target)
                i = m + 1;
            else if (numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
            else
                numbers[i] + numbers[j] < target ? ++i : --j;
        }
        return {0, 0};
    }
};