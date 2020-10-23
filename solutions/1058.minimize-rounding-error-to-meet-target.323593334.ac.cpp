class Solution {
public:
  string minimizeError(vector<string> &prices, int target) {
    vector<int> arr;

    for (auto &p : prices) {
      int v = round(stof(p) * 1000);
      target -= v / 1000;
      v %= 1000;
      if (v)
        arr.push_back(v);
    }

    if (target < 0)
      return "-1";
    if (target > arr.size())
      return "-1";

    sort(arr.begin(), arr.end());

    int ones = target;
    int zeroes = (int)arr.size() - ones;

    int ans = accumulate(arr.begin(), arr.begin() + zeroes, 0);

    ans += ones * 1000 - accumulate(arr.begin() + zeroes, arr.end(), 0);

    string output = to_string(ans / 1000) + ".";

    ans %= 1000;

    output += to_string(ans / 100);
    ans %= 100;
    output += to_string(ans / 10);
    ans %= 10;
    output += to_string(ans);
    return output;
  }
};
