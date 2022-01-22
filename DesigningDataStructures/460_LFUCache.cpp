#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class LFUCache
{
public:
    LFUCache(int capacity)
    {
    }
    int get(int key)
    {
    }
    void put(int key, int value)
    {
    }
};
TEST(LFUCache, 1)
{
    LFUCache lfu(2);
    lfu.put(1, 1);            // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);            // cache=[2,1], cnt(2)=1, cnt(1)=1
    EXPECT_EQ(lfu.get(1), 1); // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);            // cache=[3,1], cnt(3)=1, cnt(1)=2 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
    EXPECT_EQ(lfu.get(2), -1);
    EXPECT_EQ(lfu.get(3), 3); // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);            // cache=[4,3], cnt(4)=1, cnt(3)=2 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
    EXPECT_EQ(lfu.get(1), -1);
    EXPECT_EQ(lfu.get(3), 3); // cache=[3,4], cnt(4)=1, cnt(3)=3
    EXPECT_EQ(lfu.get(4), 4); // cache=[3,4], cnt(4)=2, cnt(3)=3
}