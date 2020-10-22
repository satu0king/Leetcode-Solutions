class Solution {
public:
  int minimumLengthEncoding(vector<string> &words) {
    sort(words.begin(), words.end(), [](const string &s1, const string &s2) {
      return s1.size() > s2.size();
    });

    unordered_set<int> hashes;
    int ans = 0;
    int count = 0;
    for (auto &w : words) {
      long hash = 0;
      const int p = 1e9 + 7;
      for (int i = w.size() - 1; i >= 0; i--) {
        hash = hash * 257 + w[i];
        hash %= p;
        if (i)
          hashes.insert(hash);
      }
      if (!hashes.count(hash)) {
        ans += w.size();
        count++;
        hashes.insert(hash);
      }
    }
    return ans + count;
  }
};
