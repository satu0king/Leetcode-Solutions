class Solution {
public:
  bool canConstruct(string s, int k) {
    if (s.size() < k)
      return false;
    vector<int> count(26);
    for (char c : s)
      count[c - 'a']++;
    int oddCount = 0;
    for (int i = 0; i < 26; i++)
      oddCount += count[i] % 2;

    return oddCount <= k;
  }
};
