class Solution {
public:
  int findTheLongestSubstring(string s) {
    vector<int> mp(1 << 5, -1);
    mp[0] = -1;
    int key = 0;

    vector<int> vovels(256, -1);
    vovels['a'] = 0;
    vovels['e'] = 1;
    vovels['i'] = 2;
    vovels['o'] = 3;
    vovels['u'] = 4;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {

      if (int j = vovels[s[i]]; ~j)
        key ^= (1 << j);

      if (!key || ~mp[key])
        ans = max(ans, i - mp[key]);
      else
        mp[key] = i;
    }
    return ans;
  }
};
