#include <bits/extc++.h>
#include "Iterator.hpp"
#include "gtest/gtest.h"
using namespace std;
class PeekingIterator : public Iterator
{
    bool h = false;
    int n = 0;

  public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        if (h = Iterator::hasNext())
            n = Iterator::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        return n;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        int N = n;
        if (h = Iterator::hasNext())
            n = Iterator::next();
        return N;
    }

    bool hasNext() const
    {
        return h;
    }
};
TEST(PeekingIterator, 1)
{
    PeekingIterator peekingIterator({1, 2, 3}); // [1,2,3]
    peekingIterator.next();                     // 返回 1 ，指针移动到下一个元素 [1,2,3]
    peekingIterator.peek();                     // 返回 2 ，指针未发生移动 [1,2,3]
    peekingIterator.next();                     // 返回 2 ，指针移动到下一个元素 [1,2,3]
    peekingIterator.next();                     // 返回 3 ，指针移动到下一个元素 [1,2,3]
    peekingIterator.hasNext();                  // 返回 False
}