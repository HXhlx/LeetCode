#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time)
    {
        vector<int> vs(time);
        int last = 0, ret = 0, pre = 0;
        for (vector<int>& c : clips)
            if (c[0] < time)
                vs[c[0]] = max(vs[c[0]], c[1]);
        for (wint_t i = 0; i < time; ++i) {
            last = max(last, vs[i]);
            if (i == last)
                return EOF;
            if (i == pre) {
                ++ret;
                pre = last;
            }
        }
        return ret;
    }
};