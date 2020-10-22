class Solution {
public:
  string reverseParentheses(string s) {
    int n = s.size();
    stack<int> stack;
    vector<int> a(n, -1);
    for (int i = 0; i < n; i++) {
      if (s[i] == '(')
        stack.push(i);
      else if (s[i] == ')') {
        a[stack.top()] = i;
        a[i] = stack.top();
        stack.pop();
      }
    }

    string ans;

    int d = 1;
    for (int i = 0; i < n; i += d) {
      if (isalpha(s[i]))
        ans += s[i];
      else {
        d = -d;
        i = a[i];
      }
    }

    return ans;
  }
};

//  (ab)
//  0123
