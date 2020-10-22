class Solution {
public:
  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](int a, int b) -> bool {
      string p = to_string(a) + to_string(b);
      string q = to_string(b) + to_string(a);
      return p > q;
    });
    string ans = "";
    for (int i : nums) {
      ans += to_string(i);
    }
    if (ans[0] == '0') {
      return ans.substr(0, 1);
    }
    return ans;
  }
};
