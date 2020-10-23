class Solution {
public:
  vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
    vector<int> a(length);
    for (auto update : updates) {
      a[update[0]] += update[2];
      if (update[1] + 1 < length)
        a[update[1] + 1] -= update[2];
    }
    for (int i = 1; i < length; i++)
      a[i] += a[i - 1];
    return a;
  }
};
