class Solution {
public:
  int countTriplets(vector<int> &A) {
    int n = A.size();
    int ans = 0;
    unordered_map<int, int> mp;
    for (auto n1 : A)
      for (auto n2 : A)
        mp[n1 & n2]++;

    for (auto p : mp)
      for (auto n : A)
        if ((p.first & n) == 0)
          ans += p.second;

    return ans;
  }
};
