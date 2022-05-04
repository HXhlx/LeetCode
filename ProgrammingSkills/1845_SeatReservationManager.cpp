#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class SeatManager
{
    priority_queue<unsigned, vector<unsigned>, greater<>> sm;

  public:
    SeatManager(int n)
    {
        for (unsigned sn = 1; sn <= n; ++sn)
            sm.emplace(sn);
    }
    int reserve()
    {
        unsigned sn = sm.top();
        sm.pop();
        return sn;
    }
    void unreserve(int seatNumber) { sm.emplace(seatNumber); }
};
/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(sn);
 */