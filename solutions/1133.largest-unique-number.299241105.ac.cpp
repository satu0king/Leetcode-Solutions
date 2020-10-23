class Solution {
public:
  int largestUniqueNumber(vector<int> &A) {
    map<int, int> mp;
    for (int a : A)
      mp[-a]++;

    for (auto p : mp)
      if (p.second == 1)
        return -p.first;
    return -1;
  }
};
