#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
struct LinkList
{
    int val;
    shared_ptr<LinkList> next;
    LinkList(int v = 0, shared_ptr<LinkList> node = nullptr) : val(v), next(node) {}
};
class MyLinkedList
{
    shared_ptr<LinkList> head = make_shared<LinkList>();
    int size = 0;

public:
    MyLinkedList() = default;
    int get(int index)
    {
        if (index < 0 || index >= size)
            return EOF;
        shared_ptr<LinkList> node = head->next;
        while (index--)
            node = node->next;
        return node->val;
    }
    void addAtHead(int val)
    {
        shared_ptr<LinkList> node(make_shared<LinkList>(val, head->next));
        head->next = node->next;
        ++size;
    }
    void addAtTail(int val)
    {
        shared_ptr<LinkList> tail = head;
        while (tail->next)
            tail = tail->next;
        tail->next = make_shared<LinkList>(val);
        ++size;
    }
    void addAtIndex(int index, int val)
    {
        if (index < 0)
            addAtHead(val);
        if (index >= size)
            return;
        shared_ptr<LinkList> i = head, node(make_shared<LinkList>(val));
        while (index--)
            i = i->next;
        node->next = i->next;
        i->next = node;
        ++size;
    }
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        shared_ptr<LinkList> node = head;
        while (index--)
            node = node->next;
        node->next = node->next->next;
        --size;
    }
};
TEST(DesignLinkedList, 1)
{
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2); //链表变为1-> 2-> 3
    EXPECT_EQ(linkedList.get(1), 2);
    linkedList.deleteAtIndex(1); //现在链表是1-> 3
    EXPECT_EQ(linkedList.get(1), 3);
}