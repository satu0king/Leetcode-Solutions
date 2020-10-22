class Solution {
public:
  int size_limit, open_limit;
  vector<string> ans;
  void dfs(string s, int open, int unmatched_open) {
    if (s.size() == size_limit and open == open_limit and unmatched_open == 0) {
      ans.push_back(s);
    }
    if (open > open_limit or s.size() > size_limit or
        unmatched_open > open_limit or unmatched_open < 0)
      return;
    dfs(s + '(', open + 1, unmatched_open + 1);
    dfs(s + ')', open, unmatched_open - 1);
  }
  vector<string> generateParenthesis(int n) {
    size_limit = 2 * n;
    open_limit = n;
    dfs("", 0, 0);
    return ans;
  }
};
