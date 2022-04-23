#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        wint_t low = 1, high = arr.size() - 2;
        while (low < high)
        {
            wint_t mid = (low + high) >> 1;
            if (arr[mid] < arr[mid - 1])
                high = mid;
            else if (arr[mid] < arr[mid + 1])
                low = mid + 1;
            else
                return mid;
        }
        return low;
    }
};