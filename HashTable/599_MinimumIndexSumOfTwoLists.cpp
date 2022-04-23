#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, wint_t> ids;
        vector<string> res;
        wint_t n1 = list1.size(), n2 = list2.size(), m = SHRT_MAX;
        for (wint_t i = 0; i < n1; ++i)
            ids[list1[i]] = i;
        for (wint_t i = 0; i < n2; ++i)
            if (ids.find(list2[i]) != ids.end())
            {
                wint_t j = ids[list2[i]] + i;
                if (j < m)
                {
                    m = j;
                    res.clear();
                }
                if (j == m)
                    res.emplace_back(list2[i]);
            }
        return res;
    }
};