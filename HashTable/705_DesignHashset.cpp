#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class MyHashSet
{
    unique_ptr<list<int>[]> sets;
    static const int base = 9973;
    static int hash(int key)
    {
        return key % base;
    }

public:
    MyHashSet()
    {
        sets.reset(new list<int>[base]);
    }
    void add(int key)
    {
        sets[hash(key)].emplace_back(key);
    }
    void remove(int key)
    {
        sets[hash(key)].remove(key);
    }
    bool contains(int key)
    {
        list<int> &s = sets[hash(key)];
        return find(s.begin(), s.end(), key) != s.end();
    }
};