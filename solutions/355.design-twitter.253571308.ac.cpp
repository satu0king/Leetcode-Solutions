class Twitter {

  unordered_map<int, unordered_set<int>> follows;
  unordered_map<int, vector<pair<int, int>>> tweets;

  int tweetTime;

public:
  /** Initialize your data structure here. */
  Twitter() : tweetTime(0) {}

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    tweets[userId].emplace_back(tweetTime++, tweetId);
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {

    vector<pair<int, int>> feed;

    if (tweets[userId].size() <= 10)
      feed.insert(feed.end(), tweets[userId].begin(), tweets[userId].end());
    else
      feed.insert(feed.end(), tweets[userId].end() - 10, tweets[userId].end());

    for (auto followId : follows[userId]) {
      if (tweets[followId].size() <= 10)
        feed.insert(feed.end(), tweets[followId].begin(),
                    tweets[followId].end());
      else
        feed.insert(feed.end(), tweets[followId].end() - 10,
                    tweets[followId].end());
    }

    sort(feed.begin(), feed.end());
    reverse(feed.begin(), feed.end());
    feed.erase(unique(feed.begin(), feed.end()), feed.end());
    feed.resize(min(10, (int)feed.size()));
    vector<int> ans;

    for (auto p : feed)
      ans.push_back(p.second);

    return ans;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    follows[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
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
