#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class MedianFinder {
    priority_queue<int> Min;
    priority_queue<int, vector<int>, greater<int>> Max;

public:
    MedianFinder() = default;
    void addNum(int num)
    {
        if (Min.empty() || num <= Min.top()) {
            Min.emplace(num);
            if (Max.size() + 1 < Min.size()) {
                Max.emplace(Min.top());
                Min.pop();
            }
        } else {
            Max.emplace(num);
            if (Max.size() > Min.size()) {
                Min.emplace(Max.top());
                Max.pop();
            }
        }
    }
    double findMedian()
    {
        return Min.size() > Max.size() ? Min.top() : (Min.top() + Max.top()) / 2.;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */