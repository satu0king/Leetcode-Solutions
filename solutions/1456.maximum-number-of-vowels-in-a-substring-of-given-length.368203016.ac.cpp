class Solution {
public:
  int maxVowels(string s, int k) {
    int ans = 0;
    int c = 0;
    vector<bool> vowels(256);
    vowels['a'] = vowels['e'] = vowels['i'] = vowels['o'] = vowels['u'] = true;
    for (int i = 0; i < s.size(); i++) {
      c += vowels[s[i]];
      if (i - k >= 0)
        c -= vowels[s[i - k]];
      ans = max(ans, c);
    }
    return ans;
  }
};
