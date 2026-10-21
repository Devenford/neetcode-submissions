#include<queue>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Twitter {
    int counter = 0;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    // <user id, <tweet id, count of counter when the tweet was posted>
    unordered_map<int, unordered_set<int>> followMap;
    // <follower id, <followee>>

public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        counter++;
        tweetMap[userId].push_back({tweetId, counter});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> maxHeap;
        // <counter, tweetId, userId, index position of tweet in user's list of posted tweets>
        followMap[userId].insert(userId); // a person follows themselves, i.e. the news feed also contains their own posts
        for (int u : followMap[userId]) {
            if (!tweetMap[u].empty()) {
                maxHeap.push({tweetMap[u].back().second, tweetMap[u].back().first, u, (int) tweetMap[u].size() - 1});
            }
        }

        vector<int> newsFeed;
        while (newsFeed.size() < 10 && !maxHeap.empty()) {
            vector<int> post = maxHeap.top();
            maxHeap.pop();
            newsFeed.push_back(post[1]);
            if (post[3] > 0) {
                maxHeap.push({tweetMap[post[2]][post[3] - 1].second, tweetMap[post[2]][post[3] - 1].first, post[2], post[3] - 1});
            }
        }

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
