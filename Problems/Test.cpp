#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
int main()
{
    bitset<30> a(5);
    for (wint_t i = 0; i < 30; ++i)
        cout << a[i];
}