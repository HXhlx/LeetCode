#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class RandomizedSet
{
    unordered_map<int, unsigned> idx;
    vector<int> nums;
    default_random_engine dre;

public:
    RandomizedSet() = default;
    bool insert(int val)
    {
        if (idx.find(val) != idx.end())
            return false;
        idx[val] = nums.size();
        nums.emplace_back(val);
        return true;
    }
    bool remove(int val)
    {
        if (idx.find(val) == idx.end())
            return false;
        idx[nums.back()] = idx[val];
        nums[idx[val]] = nums.back();
        idx.erase(val);
        nums.pop_back();
        return true;
    }
    int getRandom()
    {
        uniform_int_distribution<> u(0, nums.size() - 1);
        return nums[u(dre)];
    }
};
TEST(InsertDeleteGetrandomO1, 1)
{
    RandomizedSet obj;
    EXPECT_TRUE(obj.insert(1));
    EXPECT_FALSE(obj.remove(2));
    EXPECT_TRUE(obj.insert(2));
    obj.getRandom();
    EXPECT_TRUE(obj.remove(1));
    EXPECT_FALSE(obj.insert(2));
    EXPECT_EQ(obj.getRandom(), 2);
}