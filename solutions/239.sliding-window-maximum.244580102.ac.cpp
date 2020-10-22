class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> deque1;

    for (int i = 0; i < k; i++) {
      while (deque1.size() && deque1.back() < nums[i])
        deque1.pop_back();
      deque1.push_back(nums[i]);
    }

    vector<int> ans;

    if (k > nums.size() || k == 0)
      return ans;

    ans.push_back(deque1.front());

    for (int i = k; i < nums.size(); i++) {
      if (deque1.front() == nums[i - k])
        deque1.pop_front();

      while (deque1.size() && deque1.back() < nums[i])
        deque1.pop_back();
      deque1.push_back(nums[i]);
      ans.push_back(deque1.front());
    }

    return ans;
  }
};
