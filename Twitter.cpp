#include <bits/stdc++.h>

using namespace std;

class Tweet {
public:
    int tweetId;
    int timestamp;
    Tweet* next;

    Tweet(int tweetId, int timestamp) {
        this->tweetId = tweetId;
        this->next = NULL;
        this->timestamp = timestamp;
    }
};

class Tweet {
public:
    int tweetId;
    int timestamp;
    Tweet* next;

    Tweet(int tweetId, int timestamp) {
        this->tweetId = tweetId;
        this->next = NULL;
        this->timestamp = timestamp;
    }
};

class Twitter {
public:
    int timestamp = 0;
    unordered_map<int, Tweet*> mp;
    unordered_map<int, unordered_set<int>> follows;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if (mp.count(userId) == 0) {
            mp[userId] = new Tweet(tweetId, timestamp);
        } else {
            Tweet* second = mp[userId];
            mp[userId] = new Tweet(tweetId, timestamp);
            mp[userId]->next = second;
        }
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        Tweet* ptr = mp[userId];
        int count = 10;
        while (ptr and count--) { 
            pq.push({ptr->timestamp, ptr->tweetId});
            ptr = ptr->next;
        }
        for (int followee : follows[userId]) {
            Tweet* ptr = mp[followee];
            count = 10;
            while (ptr and count--) { 
                pq.push({ptr->timestamp, ptr->tweetId});
                ptr = ptr->next;
            }
        }
        vector<int> feed;
        int totalCount = 10;
        while (!pq.empty() and totalCount--) {
            auto [timestamp, tweetId] = pq.top();
            pq.pop();
            feed.push_back(tweetId);
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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
