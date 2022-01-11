#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 */
int guess(int num);
class Solution
{
  public:
    int guessNumber(int n)
    {
        for (size_t l = 1, h = n; l < h;)
        {
            size_t m = (l + h) >> 1;
            switch (guess(m))
            {
            case -1:
                h = m;
                break;
            case 0:
                return m;
                break;
            case 1:
                l = m + 1;
                break;
            }
        }
        return n;
    }
};