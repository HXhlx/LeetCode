#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    string interpret(string command)
    {
        string i;
        for (wint_t g = 0, l = command.length(); g < l;)
            switch (command[g])
            {
            case '(':
                switch (command[g + 1])
                {
                case ')':
                    i += 'o';
                    g += 2;
                    break;
                default:
                    i += "al";
                    g += 4;
                    break;
                }
                break;
            default:
                i += command[g];
                ++g;
                break;
            }
        return i;
    }
};