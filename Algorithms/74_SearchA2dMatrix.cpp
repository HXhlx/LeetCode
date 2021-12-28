#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int low = 0, high = matrix.size() - 1;
        if (matrix[low][0] == target || matrix[high][0] == target)
            return true;
        while (low < high)
        {
            int mid = (low + high) >> 1;
            if (matrix[mid][0] > target)
                high = mid;
            else if (matrix[mid][0] < target)
                low = mid + 1;
            else
                return true;
        }
        low = matrix[low][0] < target ? low : max(low - 1, 0);
        return binary_search(matrix[low].begin(), matrix[low].end(), target);
    }
};