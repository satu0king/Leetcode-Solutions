class Solution {
public:
  int minStartValue(vector<int> &nums) {
    int s = 0;
    int mn = INT_MAX;
    for (int a : nums) {
      s += a;
      mn = min(s, mn);
    }

    return max(-mn + 1, 1);
  }
};
