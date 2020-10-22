class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> s;
    unordered_map<int, int> mp;
    for (int i = nums2.size() - 1; i >= 0; i--) {
      while (s.size() && s.top() < nums2[i])
        s.pop();

      if (s.size())
        mp[nums2[i]] = s.top();
      else
        mp[nums2[i]] = -1;

      s.push(nums2[i]);
    }

    vector<int> ans;
    for (int a : nums1)
      ans.push_back(mp[a]);

    return ans;
  }
};
