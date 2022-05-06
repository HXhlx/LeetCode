#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class UndergroundSystem
{
    unordered_map<string, unordered_map<string, pair<unsigned, wint_t>>> dus;
    unordered_map<unsigned, pair<string, unsigned>> us;

  public:
    UndergroundSystem() = default;

    void checkIn(int id, string stationName, int t)
    {
        us[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        dus[us[id].first][stationName] = {dus[us[id].first][stationName].first + t - us[id].second, dus[us[id].first][stationName].second + 1};
        us.erase(id);
    }

    double getAverageTime(string startStation, string endStation)
    {
        return 1. * dus[startStation][endStation].first / dus[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */