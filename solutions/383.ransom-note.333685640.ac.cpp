class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> mp(256);
    for (char c : magazine)
      mp[c]++;
    for (char c : ransomNote)
      if (mp[c]-- == 0)
        return false;

    return true;
  }
};
