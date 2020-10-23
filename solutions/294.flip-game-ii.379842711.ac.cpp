class Solution {
public:
  bool canWin(string s) {
    int n = s.size();
    if (n == 0)
      return false;
    vector<int> piles;
    int currlen = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '+') {
        currlen++;
      } else {
        if (currlen > 1) {
          piles.push_back(currlen);
        }
        currlen = 0;
      }
    }

    if (currlen > 1) {
      piles.push_back(currlen);
    }

    if (piles.empty())
      return false;

    int mx_len = *max_element(piles.begin(), piles.end());

    vector<int> grundy(mx_len + 2);

    for (int i = 2; i <= mx_len; i++) {
      set<int> reachable;

      // cout << i << endl;
      for (int j = 0; j < ((i + 1) / 2); j++) {
        int left = j;
        int right = i - j - 2;
        // cout << left << " " << right << " " << i << endl;
        reachable.insert(grundy[left] ^ grundy[right]);
      }

      int curr = 0;
      while (reachable.count(curr))
        curr++;
      cout << i << " " << curr << endl;
      grundy[i] = curr;
    }

    int ans = 0;
    for (auto i : piles) {
      cout << i << endl;
      ans ^= grundy[i];
    }

    return (ans != 0);
  }
};
