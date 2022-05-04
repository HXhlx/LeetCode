#include "gtest/gtest.h"
#include <bits/extc++.h>
using namespace std;
class Solution
{
  public:
    int nextGreaterElement(int n)
    {
        string nge = to_string(n);
        return next_permutation(nge.begin(), nge.end()) && stoull(nge) <= INT_MAX ? stoi(nge) : EOF;
    }
};