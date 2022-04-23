#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        vector<char>::iterator it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? letters.front() : *it;
    }
};