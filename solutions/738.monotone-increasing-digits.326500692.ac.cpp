class Solution {
public:
  int monotoneIncreasingDigits(int N) {
    string s = to_string(N);
    int n = s.size();
    int i;
    for (i = 1; i < n; i++) {
      if (s[i] < s[i - 1])
        break;
    }

    if (i == n)
      return N;

    string ans(i, '0');
    ans += string(n - i, '9');
    ans[i - 1] = s[i - 1] - 1;
    for (int j = i - 2; j >= 0; j--) {
      if (s[j] > ans[j + 1]) {
        ans[j] = s[j] - 1;
        ans[j + 1] = '9';
      } else
        ans[j] = s[j];
    }

    return stoi(ans);
  }
};
