class Solution {
public:
  vector<int> transformArray(vector<int> &arr) {

    int n = arr.size();
    vector<int> temp(arr.size());
    while (true) {
      temp = arr;

      for (int i = 1; i < n - 1; i++) {
        int l = arr[i - 1];
        int r = arr[i + 1];
        if (arr[i] < min(l, r))
          temp[i] = arr[i] + 1;
        else if (arr[i] > max(l, r))
          temp[i] = arr[i] - 1;
      }

      if (temp == arr)
        return temp;
      swap(temp, arr);
    }
  }
};
