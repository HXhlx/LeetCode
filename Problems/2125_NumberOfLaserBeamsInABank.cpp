#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
  public:
    int numberOfBeams(vector<string> &bank)
    {
        int nob = 0;
        wint_t bn = 0;
        for (string &b : bank)
            if (wint_t bc = count(b.begin(), b.end(), '1'); bc)
            {
                nob += bn * bc;
                bn = bc;
            }
        return nob;
    }
};