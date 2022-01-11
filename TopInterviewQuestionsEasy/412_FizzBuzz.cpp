#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> fbs;
        for (int i = 1; i <= n; ++i)
        {
            string fb = "";
            if (i % 3 == 0)
                fb += "Fizz";
            if (i % 5 == 0)
                fb += "Buzz";
            if (fb.empty())
                fb += to_string(i);
            fbs.emplace_back(fb);
        }
        return fbs;
    }
};