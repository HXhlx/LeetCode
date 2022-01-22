#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class LRUCache
{
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int c;

public:
    LRUCache(int capacity) : c(capacity) {}
    int get(int key)
    {
        if (m.find(key) == m.end())
            return EOF;
        else
        {
            l.emplace_back(*m[key]);
            l.erase(m[key]);
            m[key] = l.end();
            --m[key];
            return l.back().second;
        }
    }
    void put(int key, int value)
    {
        if (m.find(key) != m.end())
            l.erase(m[key]);
        else if (l.size() == c)
        {
            m.erase(l.front().first);
            l.pop_front();
        }
        l.emplace_back(key, value);
        m[key] = l.end();
        --m[key];
    }
};
TEST(LRUCache, 1)
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    EXPECT_EQ(lRUCache.get(1), 1);
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache.get(2);    // 返回 -1 (未找到)
    EXPECT_EQ(lRUCache.get(2), -1);
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    EXPECT_EQ(lRUCache.get(1), -1);
    EXPECT_EQ(lRUCache.get(3), 3);
    EXPECT_EQ(lRUCache.get(4), 4);
}