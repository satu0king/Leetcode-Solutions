class Solution {
public:
  bool isPossibleDivide(vector<int> &nums, int k) {
    map<int, int> mp;
    for (int n : nums)
      mp[n]++;

    for (auto [key, v] : mp) {
      if (v) {
        for (int i = key; i < key + k; i++) {
          mp[i] -= v;
          if (mp[i] < 0)
            return false;
        }
      }
    }

    return true;
  }
};
