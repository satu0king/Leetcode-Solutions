class Solution {
public:
  bool canConvert(string str1, string str2) {
    unordered_map<char, unordered_set<char>> mp;

    int c = 0;

    unordered_set<char> target;

    bool flag = true;

    for (int i = 0; i < str1.size(); i++) {
      char c1 = str1[i];
      char c2 = str2[i];

      if (c1 != c2)
        flag = false;

      target.insert(c2);

      mp[c1].insert(c2);
      if (mp[c1].size() > 1)
        return false;
    }

    return flag || target.size() < 26;
  }
};
