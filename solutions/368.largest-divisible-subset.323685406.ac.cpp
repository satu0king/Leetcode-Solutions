class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (!n)
      return {};
    vector<int> prev(n, -1);
    vector<int> size(n, 1);

    int ans = 0;

    for (int i = 0; i < n; i++) {

      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0 && size[i] < size[j] + 1) {
          size[i] = size[j] + 1;
          prev[i] = j;
        }
      }

      if (size[i] > size[ans])
        ans = i;
    }

    vector<int> result;

    while (ans >= 0) {
      result.push_back(nums[ans]);
      ans = prev[ans];
    }

    return result;
  }
};
