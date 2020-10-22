class Solution {
public:
  int maxDistToClosest(vector<int> &seats) {
    vector<int> ones;

    for (int i = 0; i < seats.size(); i++) {
      if (seats[i])
        ones.push_back(i);
    }

    int ans = 1;
    ans = max(ones[0], ans);
    ans = max((int)seats.size() - ones.back() - 1, ans);

    for (int i = 0; i < ones.size() - 1; i++)
      ans = max(ans, (ones[i + 1] - ones[i]) / 2);

    return ans;
  }
};
