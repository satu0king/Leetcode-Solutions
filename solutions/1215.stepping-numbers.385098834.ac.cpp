class Solution {
public:
  vector<int> ans;
  vector<int> dig;
  void get(int ind, int no, int low, int mx, int len, int prev = -1) {
    if (ind == len) {
      ans.push_back(no);
      return;
    }
    if (low) {
      if (prev != -1) {
        if (prev - 1 >= 0) {
          int nxt = (no * 10) + (prev - 1);
          get(ind + 1, nxt, low, mx, len, prev - 1);
        }
        if (prev + 1 < 10) {
          int nxt = (no * 10) + prev + 1;
          get(ind + 1, nxt, low, mx, len, prev + 1);
        }

      } else {
        get(ind + 1, 0, 1, mx, len, -1);
        for (int i = 1; i < 10; i++) {
          get(ind + 1, i, 1, mx, len, i);
        }
      }

      return;
    } else {
      if (prev == -1) {
        get(ind + 1, 0, 1, mx, len, -1);
        for (int i = 1; i < dig[ind]; i++) {
          get(ind + 1, i, 1, mx, len, i);
        }
        get(ind + 1, dig[ind], 0, mx, len, dig[ind]);
      } else {
        if (prev - 1 >= 0 && (prev - 1) <= dig[ind]) {
          int nxt = (no * 10) + (prev - 1);
          get(ind + 1, nxt, (prev - 1) < dig[ind], mx, len, prev - 1);
        }

        if (prev + 1 < 10 && (prev + 1) <= dig[ind]) {
          int nxt = (no * 10) + prev + 1;
          get(ind + 1, nxt, (prev + 1) < dig[ind], mx, len, prev + 1);
        }
      }
    }
  }

  vector<int> countSteppingNumbers(int low, int high) {
    int temp = high;
    int len = 0;
    while (temp) {
      dig.push_back(temp % 10);
      len++;
      temp /= 10;
    }
    reverse(dig.begin(), dig.end());
    get(0, 0, 0, high, len);
    sort(ans.rbegin(), ans.rend());
    while (!ans.empty() && ans.back() < low)
      ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
