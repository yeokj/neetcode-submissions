class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> post;
    unordered_map<int, unordered_set<int>> followers;
    int timeStamp;

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({timeStamp, tweetId});
        ++timeStamp;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        vector<int> results;
        int k = 10;

        if (post.count(userId) && !post[userId].empty()) {
            int userIdx = post[userId].size() - 1;
            int userTime = post[userId][userIdx].first;
            pq.push({userTime, userId, userIdx});
        }

        for (int followee : followers[userId]) {
            if (post.count(followee) && !post[followee].empty()) {
                int followeeIdx = post[followee].size() - 1;
                int followeeTime = post[followee][followeeIdx].first;
                pq.push({followeeTime, followee, followeeIdx});
            }
        }

        while (!pq.empty() && results.size() < k) {
            int id = pq.top()[1], idx = pq.top()[2];
            pq.pop();

            results.push_back(post[id][idx].second);

            if (idx > 0) {
                int prevIdx = idx - 1;
                int prevTime = post[id][prevIdx].first;
                pq.push({prevTime, id, prevIdx});
            }
        }
        
        return results;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (followers[followerId].count(followeeId)) return;

        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (!followers[followerId].count(followeeId)) return;

        followers[followerId].erase(followeeId);
    }
};
