class Twitter {
   public:
    unordered_map<int, set<int>> followeesOf;
    unordered_map<int, vector<pair<int, int>>> postOf;
    int time;
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        postOf[userId].push_back({time, tweetId}); //
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        // user1 -> set (user1,user2,user3)
        followeesOf[userId].insert(userId);

        // user1 ->vector 123454
        // user2 ->vector
        // user3 ->vector
        // top k
        vector<int> tweetIds;
        priority_queue<vector<int>> maxHeap;
        for (auto user : followeesOf[userId]) {
            int idx = postOf[user].size() - 1;
            if(idx>=0){
            auto lastEl = postOf[user][idx];  // pp ->time,tweetid
            maxHeap.push({lastEl.first, lastEl.second, idx, user});}
        }
       cout<<maxHeap.size();
        int cnt = 0;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();

            tweetIds.push_back(top[1]);
            cnt++;
            for(auto i:top){
                cout<<i<<" ";
            }
            cout<<endl;
            if (cnt == 10) {
                return tweetIds;
            }

            int user = top[3];
            int idx = top[2];
            idx--;
            if (idx >= 0) {
                auto lastEl = postOf[user][idx];
                maxHeap.push({lastEl.first, lastEl.second, idx, user});
            }
        }
        return tweetIds;
    }

    void follow(int followerId, int followeeId) {
        followeesOf[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
         followeesOf[followerId].erase(followeeId); }
};

// user1->follow user2 user3..




// user1-> user2
// follower followee 