class Twitter {
    struct Tweet {
        int id;
        int time;

        Tweet(int id, int time){
            this->id = id;
            this->time = time;
        }
    };

    struct compare {
        bool operator()(const Tweet& a, const Tweet& b){
            return a.time < b.time;
        }
    };

    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;

    int timer = 0;
public:
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, timer++});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, compare> pq;
        vector<int> ans;

        for (auto tweet: tweets[userId]) pq.push(tweet);

        for (int followee: following[userId]){
            for (auto tweet: tweets[followee]) pq.push(tweet);
        }

        while (!pq.empty() && ans.size() < 10){
            ans.push_back(pq.top().id);
            pq.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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