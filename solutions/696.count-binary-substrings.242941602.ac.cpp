class Solution {
public:
  int countBinarySubstrings(string s) {
    int n = s.size();
    if (!n)
      return 0;
    int ans = 0;

    vector<int> count(2);
    char prev = s[0];
    count[prev - '0']++;

    for (int i = 1; i < n; i++) {
      if (s[i] == prev)
        count[prev - '0']++;
      else {
        ans += min(count[0], count[1]);
        prev = s[i];
        count[prev - '0'] = 1;
      }
    }

    ans += min(count[0], count[1]);

    return ans;
  }
};
