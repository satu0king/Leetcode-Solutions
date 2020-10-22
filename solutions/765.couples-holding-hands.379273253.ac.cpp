class Solution {
public:
  int minSwapsCouples(vector<int> &row) {
    int n = row.size();
    vector<int> index(n);
    for (int i = 0; i < n; i++)
      index[row[i]] = i;
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
      int partner = row[i] ^ 1;
      int partnerIndex = index[partner];
      if (partnerIndex == i + 1)
        continue;
      ans++;
      index[row[i + 1]] = partnerIndex;
      swap(row[partnerIndex], row[i + 1]);
    }
    return ans;
  }
};
