class Solution {
public:
  vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2,
                                 vector<int> &arr3) {
    vector<int> result;
    unordered_set<int> s1(arr2.begin(), arr2.end());
    unordered_set<int> s2(arr3.begin(), arr3.end());

    for (int a : arr1)
      if (s1.count(a) && s2.count(a))
        result.push_back(a);
    return result;
  }
};
