class Solution {
public:
  int maxLength(vector<string> &arr) {

    vector<int> encodings;
    for (string &s : arr)
      encodings.push_back(encode(s));

    return dfs(encodings);
  }

  int dfs(vector<int> &arr, int code = 0, int i = 0) {
    int ans = count(code);
    if (i == arr.size())
      return ans;
    ans = max(ans, dfs(arr, code, i + 1));
    if (!(code & arr[i]))
      ans = max(ans, dfs(arr, code | arr[i], i + 1));
    return ans;
  }

  int encode(string &s) {
    int code = 0;
    for (char c : s)
      if (code & (1 << (c - 'a')))
        return 0;
      else
        code |= 1 << (c - 'a');
    return code;
  }

  int count(int code) {
    int ans = 0;
    while (code) {
      ans += code % 2;
      code /= 2;
    }
    return ans;
  }
};
