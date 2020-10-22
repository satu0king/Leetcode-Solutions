class Solution {
public:
  int longestSubstring(string s, int k) {
    int ans = 0;

    vector<vector<int>> count(27, vector<int>(26));

    for (int h = 1; h <= 26; h++) {
      int unique = 0;
      int uniqueSatisfied = 0;

      int l = 0;
      for (int r = 0; r < s.size(); r++) {

        if (count[h][s[r] - 'a']++ == 0)
          unique++;

        if (count[h][s[r] - 'a'] == k)
          uniqueSatisfied++;

        while (unique > h) {

          if (count[h][s[l] - 'a']-- == k)
            uniqueSatisfied--;

          if (count[h][s[l++] - 'a'] == 0)
            unique--;
        }

        if (uniqueSatisfied == unique) {
          ans = max(ans, r - l + 1);
        }
      }
    }

    return ans;
  }
};
