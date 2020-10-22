class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    int start = 0;
    int end = 0;

    while (end < n - 1) {
      ans++;
      int newEnd = end;
      for (int i = start; i <= end; i++) {
        newEnd = max(newEnd, i + nums[i]);
      }
      start = end + 1;
      end = newEnd;
    }

    return ans;
  }
};
