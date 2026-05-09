#define pii pair<int,int>
class Twitter {
    int timeStamp=1;
    unordered_map<int,vector<pii>>userTweetsMap;
    unordered_map<int,unordered_set<int>>followerFolloweeMap;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        userTweetsMap[userId].emplace_back(timeStamp,tweetId);
        timeStamp+=1;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        
        followerFolloweeMap[userId].insert(userId);
        
        for (int followeeId: followerFolloweeMap[userId]) {
            for(auto p: userTweetsMap[followeeId]) {
                pq.push(p);
                if(pq.size()>10) pq.pop();
            }
        }
        vector<int>latestTweets;
        while(!pq.empty()) {
            latestTweets.push_back(pq.top().second);
            pq.pop();
        }
        reverse(latestTweets.begin(),latestTweets.end());
        return latestTweets;
    }
    
    void follow(int followerId, int followeeId) {
        followerFolloweeMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerFolloweeMap[followerId].erase(followeeId);
    }
};
