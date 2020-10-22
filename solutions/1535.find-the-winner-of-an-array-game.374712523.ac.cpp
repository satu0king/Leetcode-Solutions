class Solution {
public:
  int getWinner(vector<int> &arr, int k) {
    if (k > arr.size()) {
      return *max_element(arr.begin(), arr.end());
    }
    int mx = arr[0];
    int index = 0;
    for (int i = 0; i + 1 < arr.size(); i++) {
      if (arr[i + 1] > mx) {
        mx = arr[i + 1];
        index = i;
      }
      if (i - index + 1 >= k)
        break;
    }
    return mx;
  }
};
