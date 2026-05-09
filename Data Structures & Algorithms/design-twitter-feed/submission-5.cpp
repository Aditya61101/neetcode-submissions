#define pii pair<int,int>
class Twitter {
    int timeStamp=1;
    unordered_map<int,vector<pii>>userTweetsMap;
    unordered_map<int,unordered_set<int>>followerFolloweeMap;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        userTweetsMap[userId].emplace_back(timeStamp++,tweetId);
    }
    // O(f*logf), f -> no. of followees
    vector<int> getNewsFeed(int userId) {
        // use max heap
        priority_queue<vector<int>>pq;
        
        followerFolloweeMap[userId].insert(userId);
        
        for (int followeeId: followerFolloweeMap[userId]) {
            // if the followee has not made any tweet yet
            if(!userTweetsMap.count(followeeId)) continue;

            const vector<pii>&tweets = userTweetsMap[followeeId];
            // taking only the latest tweet of each followee first, 
            // it will be at the last since we are appending tweets
            int index = tweets.size()-1;
            pq.push({tweets[index].first, tweets[index].second, index, followeeId});
        }
        vector<int>latestTweets;
        while(!pq.empty() && latestTweets.size() < 10) {
            vector<int> curr = pq.top();
            pq.pop();
            latestTweets.push_back(curr[1]);
            int index = curr[2];
            // now we go in reverse direction and put tweets in the max heap for each followee
            // this is efficient now since we only care about atmost 10 tweets
            if(index > 0) {
                pii tweet = userTweetsMap[curr[3]][index-1];
                pq.push({tweet.first, tweet.second, index-1, curr[3]});
            }
        }
        return latestTweets;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        followerFolloweeMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerFolloweeMap[followerId].erase(followeeId);
    }
};
