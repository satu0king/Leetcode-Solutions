class Solution {
public:
  int longestValidParentheses(string s) {
    int n = s.size();
    stack<int> st;
    vector<int> ans(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == ')') {
        if (!st.empty()) {
          int lp = st.top();
          st.pop();
          int ans_curr = i - lp + 1;
          if (lp != 0) {
            ans_curr += ans[lp - 1];
          }
          ans[i] = ans_curr;
          mx = max(mx, ans[i]);
        }
      } else {
        st.push(i);
      }
    }
    return mx;
  }
};
