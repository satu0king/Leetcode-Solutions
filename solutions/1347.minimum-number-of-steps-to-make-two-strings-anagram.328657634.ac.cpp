class Solution {
public:
  int minSteps(string s, string t) {
    vector<int> count(256);
    for (char c : s)
      count[c]++;
    for (char c : t)
      count[c]--;
    int ans = 0;
    for (int i = 0; i < 256; i++)
      ans += abs(count[i]);
    return ans / 2;
  }
};
