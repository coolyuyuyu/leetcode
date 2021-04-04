class Twitter {
private:
    class Tweet {
    public:
        Tweet(int id_, int time_)
            : id(id_)
            , time(time_) {}
        int id;
        int time;
    };

    class User {
    public:
        set<int> followeeIds;
        vector<Tweet> tweets;
    };

public:
    /** Initialize your data structure here. */
    Twitter()
        : m_time(0) {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        m_users[userId].tweets.emplace_back(tweetId, m_time++);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        const User& user = m_users[userId];

        typedef pair<vector<Tweet>::const_reverse_iterator, vector<Tweet>::const_reverse_iterator> IterPair;
        auto comp = [](const IterPair& p1, const IterPair& p2) -> bool {
            return (p1.first->time < p2.first->time);
        };
        priority_queue<IterPair, vector<IterPair>, decltype(comp)> pq(comp); // max_heap
        if (user.tweets.empty() == false) {
            pq.emplace(user.tweets.rbegin(), user.tweets.rend());
        }
        for (int followeeId : user.followeeIds) {
            const User& followee = m_users[followeeId];
            if (followee.tweets.empty() == false) {
                pq.emplace(followee.tweets.rbegin(), followee.tweets.rend());
            }
        }

        vector<int> tweets;
        for (int n = 10; 0 < n && !pq.empty(); --n) {
            IterPair iterPair = pq.top();
            pq.pop();

            tweets.push_back(iterPair.first->id);

            iterPair.first += 1;
            if (iterPair.first != iterPair.second) {
                pq.push(iterPair);
            }
        }

        return tweets;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        m_users[followerId].followeeIds.insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        m_users[followerId].followeeIds.erase(followeeId);
    }

private:
    map<int, User> m_users;
    int m_time;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */