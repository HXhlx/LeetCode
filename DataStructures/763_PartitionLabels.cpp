#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        array<int, 26> last;
        int len = s.size();
        for (int i = 0; i < len; ++i)
            last[s[i] - 'a'] = i;
        vector<int> part;
        for (int start = 0, end = 0, i = 0; i < len; ++i)
        {
            end = max(end, last[s[i] - 'a']);
            if (end == i)
            {
                part.emplace_back(end - start + 1);
                start = end + 1;
            }
        }
        return part;
    }
};