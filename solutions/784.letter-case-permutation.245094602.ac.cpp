class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans;
    f(ans, S);
    return ans;
  }

  void f(vector<string> &ans, string &S, int i = 0) {
    if (i == S.size()) {
      ans.push_back(S);
      return;
    }

    if (isAlpha(S[i])) {
      S[i] = toLower(S[i]);
      f(ans, S, i + 1);
      S[i] = toUpper(S[i]);
      f(ans, S, i + 1);
    } else
      f(ans, S, i + 1);
  }

  bool isAlpha(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
  }
  char toLower(char c) {
    if ('A' <= c && c <= 'Z')
      return c - 'A' + 'a';
    return c;
  }
  char toUpper(char c) {
    if ('a' <= c && c <= 'z')
      return c - 'a' + 'A';
    return c;
  }
};
