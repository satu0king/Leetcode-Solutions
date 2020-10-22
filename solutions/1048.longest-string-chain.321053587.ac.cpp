class Solution {
public:
  static bool compare(const string &s1, const string &s2) {
    return s1.length() < s2.length();
  }

  int longestStrChain(vector<string> &words) {
    sort(words.begin(), words.end(), compare);
    unordered_map<string, int> dp;
    int res = 0;
    for (string w : words) {
      dp[w] = 1;
      for (int i = 0; i < w.length(); i++) {
        string newW = w.substr(0, i) + w.substr(i + 1);
        if (dp.count(newW))
          dp[w] = max(dp[w], dp[newW] + 1);
      }
      res = max(res, dp[w]);
    }
    return res;
  }
};
