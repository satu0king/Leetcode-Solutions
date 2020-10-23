class WordDistance {
  unordered_map<string, vector<int>> mp;

public:
  WordDistance(vector<string> &words) {
    for (int i = 0; i < words.size(); i++)
      mp[words[i]].push_back(i);
  }

  int shortest(string word1, string word2) {
    auto &v1 = mp[word1];
    auto &v2 = mp[word2];

    int ans = INT_MAX;
    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
      ans = min(ans, abs(v1[i] - v2[j]));
      if (v1[i] < v2[j])
        i++;
      else
        j++;
    }

    return ans;
  }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
