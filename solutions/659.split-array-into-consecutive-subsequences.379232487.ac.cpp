class Solution {
public:
  bool isPossible(vector<int> &nums) {

    unordered_map<int, int> mp;
    for (int c : nums)
      mp[c]++;

    unordered_map<int, int> map;

    for (int c : nums) {
      if (mp[c] == 0)
        continue;
      if (map[c - 1]) {
        map[c - 1]--;
        map[c]++;
      } else if (mp[c + 1] && mp[c + 2]) {
        map[c + 2]++;
        mp[c + 1]--;
        mp[c + 2]--;
      } else
        return false;
      mp[c]--;
    }

    return true;
  }
};
