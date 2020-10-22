class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    unordered_set<int> s(arr.begin(), arr.end());
    int z = count(arr.begin(), arr.end(), 0);
    if (z >= 2)
      return true;
    s.erase(0);
    for (int a : arr)
      if (s.count(2 * a))
        return true;
    return false;
  }
};
