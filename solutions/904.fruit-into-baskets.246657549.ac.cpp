class Solution {
public:
  int totalFruit(vector<int> &tree) {
    unordered_map<int, int> mp;

    int l = 0;
    int r = 0;
    int ans = 0;
    int n = tree.size();

    while (l <= r && r < n) {
      mp[tree[r++]]++;

      while (mp.size() > 2) {
        mp[tree[l]]--;
        if (mp[tree[l]] == 0)
          mp.erase(tree[l]);
        l++;
      }
      ans = max(ans, r - l);
    }

    return ans;
  }
};
