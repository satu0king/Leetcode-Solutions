class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> stack;

    int n = nums.size();
    for (int i = n - 2; i >= 0; i--) {
      while (stack.size() && stack.back() <= nums[i])
        stack.pop_back();
      stack.push_back(nums[i]);
    }

    vector<int> ans;

    for (int i = n - 1; i >= 0; i--) {
      while (stack.size() && stack.back() <= nums[i])
        stack.pop_back();

      if (stack.size())
        ans.push_back(stack.back());
      else
        ans.push_back(-1);
      stack.push_back(nums[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
