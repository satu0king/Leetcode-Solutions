class Solution {
public:
  vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos,
                                        vector<vector<int>> &friends, int id,
                                        int level) {
    int n = friends.size();
    vector<bool> visited(n);
    visited[id] = true;
    queue<int> bfsQueue;
    bfsQueue.push(id);
    int depth = 0;
    while (bfsQueue.size()) {
      if (depth == level) {
        unordered_map<string, int> mp;
        while (bfsQueue.size()) {
          int i = bfsQueue.front();
          bfsQueue.pop();
          for (auto &m : watchedVideos[i])
            mp[m]++;
        }
        vector<pair<int, string>> arr;
        for (auto &p : mp)
          arr.emplace_back(p.second, p.first);
        sort(arr.begin(), arr.end());
        vector<string> ans;
        for (auto &p : arr)
          ans.push_back(p.second);
        return ans;
      }
      depth++;
      int k = bfsQueue.size();
      while (k--) {
        int i = bfsQueue.front();
        bfsQueue.pop();
        for (int j : friends[i]) {
          if (visited[j])
            continue;
          visited[j] = true;
          bfsQueue.push(j);
        }
      }
    }
    return {};
  }
};
