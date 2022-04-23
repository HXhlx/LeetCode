#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
struct Node
{
    unsigned key, value, freq;
    Node(unsigned k, unsigned v, unsigned f) : key(k), value(v), freq(f) {}
};
class LFUCache
{
    unsigned minfreq;
    wint_t capacity;
    unordered_map<wint_t, list<Node>::iterator> key_table;
    unordered_map<wint_t, list<Node>> freq_table;

public:
    LFUCache(int capacity) : capacity(capacity), minfreq(0)
    {
        key_table.clear();
        freq_table.clear();
    }
    int get(int key)
    {
        unordered_map<wint_t, list<Node>::iterator>::iterator it = key_table.find(key);
        if (capacity == 0 || it == key_table.end())
            return EOF;
        list<Node>::iterator node = it->second;
        unsigned value = node->value, freq = node->freq;
        freq_table[freq].erase(node);
        if (freq_table[freq].size() == 0)
        {
            freq_table.erase(freq);
            if (minfreq == freq)
                ++minfreq;
        }
        freq_table[freq + 1].emplace_front(key, value, freq + 1);
        key_table[key] = freq_table[freq + 1].begin();
        return value;
    }
    void put(int key, int value)
    {
        if (capacity == 0)
            return;
        unordered_map<wint_t, list<Node>::iterator>::iterator it = key_table.find(key);
        if (it == key_table.end())
        {
            if (key_table.size() == capacity)
            {
                key_table.erase(freq_table[minfreq].back().key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0)
                    freq_table.erase(minfreq);
            }
            freq_table[1].emplace_front(key, value, 1);
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        }
        else
        {
            list<Node>::iterator node = it->second;
            wint_t freq = node->freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0)
            {
                freq_table.erase(freq);
                if (minfreq == freq)
                    ++minfreq;
            }
            freq_table[freq + 1].emplace_front(key, value, freq + 1);
            key_table[key] = freq_table[freq + 1].begin();
        }
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