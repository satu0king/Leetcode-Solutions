class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int l = 0;
    int r = people.size() - 1;
    int ans = 0;

    while (l <= r) {
      ans++;
      if (people[l] + people[r--] <= limit)
        l++;
    }

    return ans;
  }
};
