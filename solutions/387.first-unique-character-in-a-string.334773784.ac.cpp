class Solution {
public:
  int firstUniqChar(string s) {
    vector<int> lookup(256);
    for (char c : s)
      lookup[c]++;
    for (int i = 0; i < s.size(); i++)
      if (lookup[s[i]] == 1)
        return i;

    return -1;
  }
};
