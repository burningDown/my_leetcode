class Twitter {
private:
    unordered_map<int,list<vector<int>>> userMap;
    unordered_map<int,unordered_set<int>> followMap;
    int globalTime;
public:
    /** Initialize your data structure here. */
    Twitter() {
        globalTime = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        userMap[userId].push_front({globalTime, tweetId});
        globalTime++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> &followSet = followMap[userId];
        const int l = followSet.size();
        vector<vector<list<vector<int>>::iterator>> itVector;
        vector<int> result;
        int maxIdx;

        result.reserve(10);
        itVector.reserve(l + 1);
        itVector.push_back({userMap[userId].begin(), userMap[userId].end()});

        for(unordered_set<int>::iterator it = followSet.begin();it!=followSet.end();it++)
        {
            itVector.push_back({userMap[*it].begin(), userMap[*it].end()});
        }

        for(int i=0;i<10;i++)
        {
            maxIdx = -1;
            for(int j=0;j<l+1;j++)
            {
                if(itVector[j][0] != itVector[j][1])
                {
                    if(maxIdx < 0 || (*itVector[j][0])[0] > (*itVector[maxIdx][0])[0])
                    {
                        maxIdx = j;
                    }
                }
            }

            if(maxIdx < 0)
                break;
            else
            {
                result.push_back((*itVector[maxIdx][0])[1]);
                itVector[maxIdx][0]++;
            }
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followMap[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followMap[followerId].count(followeeId) > 0)
            followMap[followerId].erase(followeeId);
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