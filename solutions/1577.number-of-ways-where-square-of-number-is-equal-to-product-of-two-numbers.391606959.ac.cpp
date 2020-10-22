class Solution {
public:
  int numTriplets(vector<int> &nums1, vector<int> &nums2) {
    return f(nums1, nums2) + f(nums2, nums1);
  }

  int f(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<long, int> set1;
    for (long a : nums1)
      set1[a * a]++;
    int ans = 0;
    for (int i = 0; i < nums2.size(); i++)
      for (int j = i + 1; j < nums2.size(); j++) {
        long t = nums2[i];
        t *= nums2[j];
        ans += set1[t];
      }
    return ans;
  }
};
