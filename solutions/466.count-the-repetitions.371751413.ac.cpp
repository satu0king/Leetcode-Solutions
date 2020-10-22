class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int len = s2.size();
    vector<int> dp(len);
    for (int i = 0; i < len; i++) {
      int start = i;
      for (char ch : s1)
        if (ch == s2[start % len])
          start++;
      if (start == i)
        return 0;
      dp[i] = start - i;
    }
    int idx = 0;
    for (int i = 0; i < n1; i++)
      idx += dp[idx % len];
    return idx / len / n2;
  }
};
