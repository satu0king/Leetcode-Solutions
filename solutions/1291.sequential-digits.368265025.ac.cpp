class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;
    for (long candidate = 1; candidate <= 9; candidate++) {
      long temp = candidate;
      while (temp <= high) {
        if (temp >= low)
          ans.push_back(temp);
        int c = temp % 10;
        if (c == 9)
          break;
        temp = temp * 10 + c + 1;
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
