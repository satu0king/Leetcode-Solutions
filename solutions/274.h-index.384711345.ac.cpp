class Solution {
public:
  int hIndex(vector<int> &citation) {
    int n = citation.size();
    sort(citation.rbegin(), citation.rend());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int req = citation[i] - i - 1;
      if (req <= 0) {
        return max(ans, citation[i]);
      }
      if (i + req < n && citation[i + req] >= citation[i]) {
        return max(ans, citation[i]);
      }
      ans = max(ans, min(i + 1, citation[i]));
    }
    return ans;
  }
};
