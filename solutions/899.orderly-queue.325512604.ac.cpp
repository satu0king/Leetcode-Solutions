class Solution {
public:
  string orderlyQueue(string S, int K) {
    string ans = S;
    if (K > 1) {
      sort(ans.begin(), ans.end());
      return ans;
    }

    S += S;

    for (int i = 0; i < ans.size(); i++) {
      ans = min(ans, S.substr(i, ans.size()));
    }
    return ans;
  }
};
