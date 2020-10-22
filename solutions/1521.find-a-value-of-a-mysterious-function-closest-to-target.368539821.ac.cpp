class Solution {
public:
  int closestToTarget(vector<int> &arr, int target) {
    int ans = abs(arr[0] - target);
    int temp = arr[0];
    int l = 0;
    int n = arr.size();
    unordered_set<int> possible = {};
    for (int i = 0; i < n; i++) {
      unordered_set<int> nextPossible = {arr[i]};
      for (int el : possible) {
        int c = el & arr[i];
        nextPossible.insert(c);
      }
      possible = move(nextPossible);
      for (int a : possible)
        ans = min(ans, abs(a - target));
    }

    return ans;
  }
};
