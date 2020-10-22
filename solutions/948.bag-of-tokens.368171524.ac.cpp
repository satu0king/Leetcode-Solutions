class Solution {
public:
  int bagOfTokensScore(vector<int> &tokens, int P) {
    sort(tokens.begin(), tokens.end());
    int l = 0;
    int r = tokens.size() - 1;
    int ans = 0;
    int temp = 0;
    while (l <= r) {
      if (tokens[l] <= P) {
        P -= tokens[l++];
        temp++;
        ans = max(ans, temp);
      } else {
        if (temp == 0)
          break;
        P += tokens[r--];
        temp--;
      }
    }
    return ans;
  }
};
