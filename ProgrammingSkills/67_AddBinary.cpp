#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        bool addOne = false;
        string ad;
        string::reverse_iterator ai = a.rbegin(), bi = b.rbegin();
        while (ai != a.rend() && bi != b.rend())
        {
            ad += *ai + *bi + addOne - '0';
            if (addOne = ad.back() >= '2')
                ad.back() -= 2;
            ++ai;
            ++bi;
        }
        while (ai != a.rend())
        {
            ad += *ai + addOne;
            if (addOne = ad.back() == '2')
                ad.back() = '0';
            ++ai;
        }
        while (bi != b.rend())
        {
            ad += *bi + addOne;
            if (addOne = ad.back() == '2')
                ad.back() = '0';
            ++bi;
        }
        if (addOne)
            ad += '1';
        reverse(ad.begin(), ad.end());
        return ad;
    }
};