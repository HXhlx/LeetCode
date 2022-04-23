#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        wint_t low = 0, high = numbers.size() - 1;
        while (low < high)
        {
            wint_t mid = (low + high) >> 1;
            if (numbers[mid] < numbers[high])
                high = mid;
            else if (numbers[mid] > numbers[high])
                low = mid + 1;
            else
            {
                while (high > mid && numbers[high] == numbers[mid])
                    --high;
                while (low < mid && numbers[low] == numbers[mid])
                    ++low;
            }
        }
        return numbers[low];
    }
};