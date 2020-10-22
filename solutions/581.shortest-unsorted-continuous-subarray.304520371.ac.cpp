class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    int n = nums.size();

    stack<int> s;

    int l = n;
    int r = 0;
    for (int i = 0; i < n; i++) {
      while (s.size() && nums[s.top()] > nums[i]) {
        l = min(l, s.top());
        s.pop();
      }
      s.push(i);
    }

    for (int i = n - 1; i >= 0; i--) {
      while (s.size() && nums[s.top()] < nums[i]) {
        r = max(r, s.top());
        s.pop();
      }
      s.push(i);
    }

    return r - l > 0 ? r - l + 1 : 0;
  }
};
