class Solution {
public:
  vector<string> removeSubfolders(vector<string> &folder) {
    sort(folder.begin(), folder.end());
    vector<string> ans = {folder[0]};
    int prev = 0;
    int n = folder.size();
    for (int i = 1; i < n; i++) {
      int t = folder[prev].size();
      if (folder[i].size() > t &&
          folder[i].substr(0, t + 1) == folder[prev] + "/")
        continue;
      prev = i;
      ans.push_back(folder[i]);
    }
    return ans;
  }
};
