class Solution {
public:
  int numKLenSubstrNoRepeats(string S, int k) {
    unordered_map<char, int> mp;
    int n = S.size();
    if (n < k)
      return 0;
    int ans = 0;

    for (int i = 0; i < k; i++)
      mp[S[i]]++;

    if (mp.size() == k)
      ans++;

    for (int i = k; i < n; i++) {
      mp[S[i - k]]--;
      if (!mp[S[i - k]])
        mp.erase(S[i - k]);

      mp[S[i]]++;

      if (mp.size() == k)
        ans++;
    }
    return ans;
  }
};
