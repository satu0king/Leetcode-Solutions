class Solution {
public:
  int kConcatenationMaxSum(vector<int> &arr, int k) {
    long long ans = 0;
    int sum = accumulate(arr.begin(), arr.end(), 0);

    int n = arr.size();

    arr.reserve(2 * n + 1);

    long long int temp = 0;

    const int p = 1e9 + 7;

    if (k > 2 && sum > 0)
      temp = sum * (k - 2LL) % p;

    if (k > 1)
      for (int i = 0; i < n; i++)
        arr.push_back(arr[i]);

    long long mi = 0;
    long long s = 0;
    for (int n : arr) {
      s += n;
      ans = max(ans, s - mi);
      mi = min(mi, s);
    }

    return (ans + temp) % p;
  }
};
