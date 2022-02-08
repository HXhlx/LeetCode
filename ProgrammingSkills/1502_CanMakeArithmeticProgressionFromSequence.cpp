#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        for (vector<int>::iterator it = arr.begin() + 2; it != arr.end(); ++it)
            if (*it - *(it - 1) != d)
                return false;
        return true;
    }
};