class Solution {
public:
  int maxNumberOfApples(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int ans = 0;
    int temp = 5000;

    for (int a : arr)
      if (a <= temp) {
        ans++;
        temp -= a;
      }

    return ans;
  }
};
