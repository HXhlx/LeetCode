#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<short> cie;
        for (int a : arr)
        {
            if (cie.find(a * 2) != cie.end() || (a & 1) == 0 && cie.find(a / 2) != cie.end())
                return true;
            cie.emplace(a);
        }
        return false;
    }
};