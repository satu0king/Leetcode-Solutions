class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> cnt(102, 0);
    for (int n : nums) {
      cnt[n + 1]++; // e.g. for n = 1, it's valid for cnt[2+] but not for cnt[1]
    }
    for (int i = 1; i < cnt.size(); ++i) {
      cnt[i] += cnt[i - 1]; // rolling counts
    }
    for (int &n : nums) {
      n = cnt[n]; // replace with counts
    }
    return nums;
  }
};
