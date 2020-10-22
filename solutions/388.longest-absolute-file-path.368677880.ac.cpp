pair<int, bool> getLength(string &file, int &i) {
  if (file[i] == '\n')
    i++;
  while (file[i] == '\t')
    i++;
  int l = 0;
  bool flag = false;
  while (i < file.length() && file[i] != '\n') {
    l++;
    if (file[i++] == '.')
      flag = true;
  }
  return {l, flag};
}

int getLevel(string &file, int i) {
  int level = 0;
  if (file[i] == '\n')
    i++;
  bool flag = false;
  while (i < file.length() && file[i] == '\t') {
    level++;
    i++;
  }
  return level;
}

int dfs(string &file, int &i, int level) {
  int ans = 0;
  int z = i;
  while (i < file.length()) {
    // cout << i << " " << getLevel(file, i) << endl;
    if (getLevel(file, i) == level) {
      auto [l, f] = getLength(file, i);
      // cout << z <<" " << l << endl;
      int z = dfs(file, i, level + 1);
      if (z)
        z++;
      if (z || f)
        ans = max(ans, l + z);
    } else
      break;
  }
  // cout << z <<" " << ans << endl;
  return ans;
}

class Solution {
public:
  int lengthLongestPath(string input) {
    int i = 0;
    return dfs(input, i, 0);
  }
};
