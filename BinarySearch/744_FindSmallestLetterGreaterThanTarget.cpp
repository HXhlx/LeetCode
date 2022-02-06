#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        wint_t l = 0, h = letters.size() - 1;
        if (letters.back() <= target)
            return letters.front();
        while (l < h)
        {
            wint_t m = midpoint(l, h);
            if (letters[m] > target)
                h = m;
            else if (letters[m] <= target)
                l = m + 1;
        }
        while (letters[l] == target)
            ++l;
        return letters[l];
    }
};