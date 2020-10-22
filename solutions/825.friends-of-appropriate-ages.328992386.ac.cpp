class Solution {
public:
  int numFriendRequests(vector<int> &ages) {
    sort(ages.begin(), ages.end());

    int ans = 0;
    for (int age : ages) {
      auto it1 = upper_bound(ages.begin(), ages.end(), 0.5 * age + 7);
      auto it2 = upper_bound(ages.begin(), ages.end(), age);
      ans += max(0L, distance(it1, it2) - 1);
    }

    return ans;
  }
};
