#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
struct User
{
    unordered_set<wint_t> fi;
    map<wint_t, wint_t> ti;
};

class Twitter
{
    array<User, 501> users{};
    wint_t Time = 0;

  public:
    Twitter() = default;

    void postTweet(int userId, int tweetId)
    {
        users[userId].ti[Time++] = tweetId;
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<wint_t, wint_t>> fs;
        vector<int> gnf;
        for (pair<const wint_t, wint_t> &t : users[userId].ti)
            fs.emplace(t);
        for (wint_t f : users[userId].fi)
        {
            for (pair<const wint_t, wint_t> &t : users[f].ti)
                fs.emplace(t);
        }
        for (wint_t i = 0; i < 10 && !fs.empty(); ++i)
        {
            gnf.emplace_back(fs.top().second);
            fs.pop();
        }
        return gnf;
    }

    void follow(int followerId, int followeeId)
    {
        users[followerId].fi.emplace(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        users[followerId].fi.erase(followeeId);
    }
};
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
TEST(DesignTwtter, 1)
{
    Twitter twitter;
    twitter.postTweet(1, 5);                                // 用户 1 发送了一条新推文 (用户 id = 1, 推文 id = 5)
    EXPECT_EQ(twitter.getNewsFeed(1), vector<int>{5});      // 用户 1 的获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
    twitter.follow(1, 2);                                   // 用户 1 关注了用户 2
    twitter.postTweet(2, 6);                                // 用户 2 发送了一个新推文 (推文 id = 6)
    EXPECT_EQ(twitter.getNewsFeed(1), vector<int>({6, 5})); // 用户 1 的获取推文应当返回一个列表，其中包含两个推文，id 分别为 -> [6, 5] 。推文 id 6 应当在推文 id 5 之前，因为它是在 5 之后发送的
    twitter.unfollow(1, 2);                                 // 用户 1 取消关注了用户 2
    EXPECT_EQ(twitter.getNewsFeed(1), vector<int>{5});      // 用户 1 获取推文应当返回一个列表，其中包含一个 id 为 5 的推文。因为用户 1 已经不再关注用户 2
}