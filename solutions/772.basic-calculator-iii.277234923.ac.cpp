class Solution {

  unordered_map<char, int> precedence;
  stack<char> operatorStack;
  stack<long long int> valueStack;

public:
  Solution() {
    precedence = {{'(', 0}, {'+', 1}, {'-', 1}, {'/', 2}, {'*', 2}};
  }
  int calculate(string s) {
    int l = 0;

    bool flag = true;

    for (int r = 0; r < s.size(); r++) {
      char c = s[r];
      if (!(isdigit(c) || flag && c == '-')) {
        if (r > l)
          valueStack.push(stol(s.substr(l, r - l))), flag = false;
        l = r + 1;
        if (c == '(')
          operatorStack.push(c), flag = true;
        else if (precedence.count(c)) {
          while (operatorStack.size() &&
                 precedence[operatorStack.top()] >= precedence[c])
            resolve();
          if (valueStack.empty())
            valueStack.push(0);
          operatorStack.push(c);
        } else if (c == ')') {
          while (operatorStack.top() != '(')
            resolve();
          operatorStack.pop();
        }
      } else
        flag = false;
    }

    if (s.size() > l)
      valueStack.push(stol(s.substr(l, s.size() - l)));

    while (operatorStack.size())
      resolve();

    return valueStack.top();
  }

  void resolve() {
    long int op2 = valueStack.top();
    valueStack.pop();
    long int op1 = valueStack.top();
    valueStack.pop();

    char op = operatorStack.top();
    operatorStack.pop();

    if (op == '+')
      valueStack.push(op1 + op2);
    else if (op == '-')
      valueStack.push(op1 - op2);
    else if (op == '*')
      valueStack.push(op1 * op2);
    else if (op == '/')
      valueStack.push(op1 / op2);
  }
};
