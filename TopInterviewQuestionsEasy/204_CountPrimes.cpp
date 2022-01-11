#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        vector<int> primes;
        bool is_prime[n];
        fill(is_prime, is_prime + n, true);
        for (int i = 2; i < n; ++i)
        {
            if (is_prime[i])
                primes.emplace_back(i);
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j)
            {
                is_prime[i * primes[j]] = false;
                if (i % primes[j] == 0)
                    break;
            }
        }
        return primes.size();
    }
};