class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int i = 0;

    if (strs.size() == 0)
      return "";

    while (1) {
      if (strs[0].size() == i)
        return strs[0].substr(0, i);
      char c = strs[0][i];
      for (auto &w : strs)
        if (w.size() == i || w[i] != c)
          return strs[0].substr(0, i);
      i++;
    }
  }
};
