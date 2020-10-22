class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = nums1.size() - 1;
    int r = n - 1;
    int l = m - 1;

    while (i > l) {
      if (l < 0 || nums2[r] > nums1[l])
        nums1[i--] = nums2[r--];
      else
        nums1[i--] = nums1[l--];
    }
  }
};
