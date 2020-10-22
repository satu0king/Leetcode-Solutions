class Solution {
public:
  int countLargestGroup(int n) {
    vector<int> map(n + 1);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
      map[i] = map[i / 10] + i % 10;
      c[map[i]]++;
    }
    int mx = *max_element(c.begin(), c.end());
    return count(c.begin(), c.end(), mx);
  }
};
