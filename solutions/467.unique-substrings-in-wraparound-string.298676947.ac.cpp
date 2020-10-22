class Solution {
public:
  int findSubstringInWraproundString(string p) {

    vector<int> alp(26, 0);

    int n = p.length();

    int len = 0, res = 0;

    for (int i = 0; i < n; i++) {
      char cur = p[i] - 'a';
      if (i > 0 && p[i - 1] != (cur + 26 - 1) % 26 + 'a')
        len = 0;
      len++;
      if (len > alp[cur]) {
        res += len - alp[cur];
        alp[cur] = len;
      }
    }
    return res;
  }
};
