#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
  public:
    bool lemonadeChange(vector<int> &bills)
    {
        map<wint_t, unsigned> lc{{5, 0}, {10, 0}, {20, 0}};
        for (int b : bills)
            switch (b)
            {
            case 5:
                ++lc[5];
                break;
            case 10:
                ++lc[10];
                if (lc[5] == 0)
                    return false;
                --lc[5];
                break;
            case 20:
                ++lc[20];
                if (lc[5] == 0)
                    return false;
                if (lc[10])
                {
                    --lc[10];
                    --lc[5];
                }
                else if (lc[5] < 3)
                    return false;
                else
                    lc[5] -= 3;
                break;
            }
        return true;
    }
};