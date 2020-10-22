class Solution {
public:
  enum Token { OP_PLUS, OP_MINUS, OPEN, CLOSE, NUM };
  vector<pair<int, int>> tokenize(const string &s) {
    int n = s.size();
    vector<pair<int, int>> ans;
    int i = 0;
    while (i < n) {
      if (s[i] == '(') {
        ans.push_back({2, 0});
      } else if (s[i] == ')') {
        ans.push_back({3, 0});

      } else if (s[i] == '+') {
        ans.push_back({0, 0});

      } else if (s[i] == '-') {
        ans.push_back({1, 0});

      } else if (s[i] != ' ') {
        string str;
        while (s[i] >= '0' and s[i] <= '9') {
          str += s[i];
          i++;
        }
        i--;
        int num = stoi(str);
        ans.push_back({4, num});
      }
      i++;
    }
    return ans;
  }
  map<int, int> ma;
  int rec(const vector<pair<int, int>> &tokens, int l, int r) {
    if (l > r)
      return 0;
    int prod = 1;
    if (tokens[l].first == 0)
      return rec(tokens, l + 1, r);
    else if (tokens[l].first == 1) {
      if (tokens[l + 1].first == 2)
        return -1 * rec(tokens, l + 1, ma[l + 1]) +
               rec(tokens, ma[l + 1] + 1, r);
      else
        return -1 * tokens[l + 1].second + rec(tokens, l + 2, r);
    } else if (tokens[l].first == 2)
      return rec(tokens, l + 1, ma[l] - 1) + rec(tokens, ma[l] + 1, r);
    int x1 = tokens[l].second;
    int y1 = rec(tokens, l + 1, r);
    return x1 + y1;
  }
  int calculate(string s) {
    vector<pair<int, int>> tokens = tokenize(s);
    int n = tokens.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
      if (tokens[i].first == 2)
        st.push(i);
      else if (tokens[i].first == 3) {
        int top = st.top();
        st.pop();
        ma[top] = i;
      }
    }
    return rec(tokens, 0, n - 1);
  }
};
