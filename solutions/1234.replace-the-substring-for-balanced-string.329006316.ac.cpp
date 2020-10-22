class Solution {
public:
  int balancedString(string s) {
    int n = s.size();
    vector<int> count(4);

    replace(s.begin(), s.end(), 'Q', '0');
    replace(s.begin(), s.end(), 'W', '1');
    replace(s.begin(), s.end(), 'E', '2');
    replace(s.begin(), s.end(), 'R', '3');
    for (char c : s)
      count[c - '0']++;

    bool flag = true;
    for (int i = 0; i < 4; i++) {
      count[i] = max(0, count[i] - n / 4);
      if (count[i])
        flag = false;
    }

    if (flag)
      return 0;

    vector<int> runningCount(4);
    int l = 0;
    int ans = n;

    auto isValid = [&]() {
      for (int i = 0; i < 4; i++)
        if (runningCount[i] < count[i])
          return false;
      return true;
    };

    for (int r = 0; r < n; r++) {
      runningCount[s[r] - '0']++;

      while (isValid()) {
        if (runningCount[s[l] - '0'] == count[s[l] - '0'])
          break;
        runningCount[s[l++] - '0']--;
      }

      if (isValid())
        ans = min(ans, r - l + 1);
    }

    return ans;
  }
};
