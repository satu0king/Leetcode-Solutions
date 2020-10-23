class Solution {
public:
  string findContestMatch(int n) {
    vector<string> ans;
    ans.reserve(n);

    for (int i = 1; i <= n; i++)
      ans.push_back(to_string(i));

    while (n > 1) {
      for (int i = 0; i < n / 2; i++)
        ans[i] = "(" + ans[i] + "," + ans[n - i - 1] + ")";

      n /= 2;
    }

    return ans[0];
  }
};
