class Solution {
public:
  vector<int> replaceElements(vector<int> &arr) {
    int greatest = -1;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--) {
      int g = arr[i];
      arr[i] = greatest;
      greatest = max(greatest, g);
    }
    return arr;
  }
};
