class Solution {
public:
  int minBuildTime(vector<int> &blocks, int split) {
    sort(blocks.rbegin(), blocks.rend());
    int l = 0, r = 1e9 + 7;
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (can(blocks, split, mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }

  bool can(vector<int> &blocks, int split, int time) {
    int workers = 1;
    int rem = blocks.size();
    for (int i : blocks) {
      if (workers <= 0 || (time - i) < 0)
        return false;
      while (i + split <= time) {
        workers *= 2;
        time -= split;
        if (workers >= rem)
          return true;
      }
      rem--;
      workers--;
    }
    return true;
  }
};
