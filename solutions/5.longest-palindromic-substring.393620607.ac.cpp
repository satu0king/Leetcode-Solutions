class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0)
      return "";

    vector<vector<bool>> dp(n, vector<bool>(n, true));
    // length is length of substring
    // 1 length substrings are palindrome
    int startIndex = 0;
    int ansLength = 1;
    for (int length = 2; length <= n; length++) {
      for (int i = 0; i < n && i + length <= n; i++) {
        int j = i + length - 1;
        dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
        if (dp[i][j]) {
          startIndex = i;
          ansLength = length;
        }
      }
    }
    return s.substr(startIndex, ansLength);
  }
};

// S[i...j] = true if S[i] = S[j] and S[i + 1...j -1] is true
