#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class ParkingSystem
{
    array<int, 4> parking;

public:
    ParkingSystem(int big, int medium, int small)
    {
        parking = {0, big, medium, small};
    }
    bool addCar(int carType)
    {
        if (parking[carType])
        {
            --parking[carType];
            return true;
        }
        else
            return false;
    }
};