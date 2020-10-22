class Solution {
public:
  string customSortString(string S, string T) {
    unordered_map<char, int> mp;
    for (int i = 0; i < S.size(); i++)
      mp[S[i]] = i;

    auto cmp = [&mp](char c1, char c2) -> bool {
      c1 = mp.count(c1) ? mp[c1] : 26;
      c2 = mp.count(c2) ? mp[c2] : 26;
      return c1 < c2;
    };

    stable_sort(T.begin(), T.end(), cmp);
    return T;
  }
};
