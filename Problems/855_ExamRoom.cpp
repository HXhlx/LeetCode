#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class ExamRoom
{
    set<unsigned> er;
    unsigned N;

  public:
    ExamRoom(int n) : N(n) {}

    int seat()
    {
        wint_t p = 0;
        if (!er.empty())
        {
            wint_t m = *er.begin();
            for (set<unsigned>::iterator R = er.begin(), L = R++; R != er.end(); ++L, ++R)
                if ((*R - *L) / 2 > m)
                {
                    p = (*L + *R) >> 1;
                    m = *R - *L >> 1;
                }
            if (*er.rbegin() != N - 1 && (N - *er.rbegin() - 1) > m)
            {
                p = N - 1;
                m = N - *er.rbegin() - 1;
            }
        }
        er.emplace(p);
        return p;
    }

    void leave(int p)
    {
        er.erase(p);
    }
};
/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
TEST(ExamRoom, 1)
{
    ExamRoom er(10);
    EXPECT_EQ(er.seat(), 0);
    EXPECT_EQ(er.seat(), 9);
    EXPECT_EQ(er.seat(), 4);
    EXPECT_EQ(er.seat(), 2);
    er.leave(4);
    EXPECT_EQ(er.seat(), 5);
}