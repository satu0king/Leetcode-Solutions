class Solution {
public:
  vector<int> findPermutation(string s) {
    stack<int> stack;
    int n = s.size();
    vector<int> ans;
    for (int i = 0; i <= n; i++) {
      stack.push(i + 1);
      if (i == n || s[i] == 'I') {
        while (stack.size()) {
          ans.push_back(stack.top());
          stack.pop();
        }
      }
    }

    return ans;
  }
};
