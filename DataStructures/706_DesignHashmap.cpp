#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class MyHashMap
{
    vector<list<pair<int, int>>> table;
    static const int base = 1021;
    static int hash(int key)
    {
        return key % base;
    }

public:
    MyHashMap() : table(base) {}
    void put(int key, int value)
    {
        list<pair<int, int>> &l = table[hash(key)];
        for (pair<int, int> &kv : l)
            if (kv.first == key)
            {
                kv.second = value;
                return;
            }
        l.emplace_back(key, value);
    }
    int get(int key)
    {
        list<pair<int, int>> &l = table[hash(key)];
        for (pair<int, int> &kv : l)
            if (kv.first == key)
                return kv.second;
        return EOF;
    }
    void remove(int key)
    {
        list<pair<int, int>> &l = table[hash(key)];
        for (list<pair<int, int>>::iterator it = l.begin(); it != l.end(); ++it)
            if (it->first == key)
            {
                l.erase(it);
                return;
            }
    }
};