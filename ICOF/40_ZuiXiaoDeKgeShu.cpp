#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        nth_element(arr.begin(), arr.begin() + k, arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};