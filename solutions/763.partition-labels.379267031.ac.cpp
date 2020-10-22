class Solution {
public:
  vector<int> partitionLabels(string S) {
    vector<int> map(256);

    int n = S.size();
    for (int i = 0; i < n; i++)
      map[S[i]] = i;

    int l = 0;
    int r = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      r = max(r, map[S[i]]);
      if (r == i) {
        ans.push_back(r - l + 1);
        r = i + 1;
        l = i + 1;
      }
    }
    return ans;
  }
};
