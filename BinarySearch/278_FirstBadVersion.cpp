#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
bool isBadVersion(int version);
class Solution
{
public:
    int firstBadVersion(int n)
    {
        size_t low = 0, high = n;
        while (low < high)
        {
            size_t mid = (low + high) / 2;
            if (isBadVersion(mid))
                high = mid;
            else
                low = mid + 1;
        }
        return high;
    }
};