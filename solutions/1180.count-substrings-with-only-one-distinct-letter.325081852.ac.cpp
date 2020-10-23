class Solution {
public:
  int countLetters(string S) {
    vector<int> count(26);
    int unique = 0;
    int ans = 0;
    int l = 0;
    for (int r = 0; r < S.size(); r++) {
      if (!count[S[r] - 'a']++)
        unique++;
      while (unique > 1)
        if (!--count[S[l++] - 'a'])
          unique--;
      ans += r - l + 1;
    }
    return ans;
  }
};
