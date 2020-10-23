class Solution {
public:
  bool areSentencesSimilar(vector<string> &words1, vector<string> &words2,
                           vector<vector<string>> &pairs) {
    unordered_map<string, unordered_set<string>> mp;
    if (words1.size() != words2.size())
      return false;
    for (auto &p : pairs) {
      mp[p[0]].insert(p[1]);
      mp[p[1]].insert(p[0]);
    }
    for (int i = 0; i < words1.size(); i++) {
      if (words1[i] == words2[i])
        continue;
      if (mp[words1[i]].count(words2[i]))
        continue;
      return false;
    }
    return true;
  }
};
