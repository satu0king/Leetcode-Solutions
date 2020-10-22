class Solution {
public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int ans = 0;
    unordered_map<int, int> mp;
    vector<int> count(26);
    int uniqueLetters = 0;
    long hash = 0;
    long h = 1;
    const long p = 1e9 + 7;
    for (int i = 0; i < s.size(); i++) {
      if (i >= minSize) {
        int c = s[i - minSize] - 'a';
        hash = (hash - h * (c + 1) + p) % p;
        count[c]--;
        if (!count[c])
          uniqueLetters--;
      } else if (i)
        h = (h * 29) % p;

      int c = s[i] - 'a';
      hash = (hash * 29 + c + 1) % p;

      if (!count[c])
        uniqueLetters++;
      count[c]++;

      if (i >= minSize - 1 && uniqueLetters <= maxLetters)
        mp[hash]++;
    }

    for (auto [hash, count] : mp)
      ans = max(ans, count);

    return ans;
  }
};
