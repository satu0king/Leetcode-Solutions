class Solution {
public:
  int calculate(string s) {
    vector<int> valueStack;
    vector<char> operatorStack;
    int n = s.size();
    int l = 0;
    int r = 0;

    unordered_map<char, int> precedence = {
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0}};

    while (r < n) {
      if (isdigit(s[r]))
        r++;
      else {
        if (r > l)
          valueStack.push_back(stoi(s.substr(l, r - l)));
        if (s[r] == '(')
          operatorStack.push_back('(');
        else if (s[r] == ')') {
          while (operatorStack.back() != '(')
            f(valueStack, operatorStack);
          operatorStack.pop_back();
        } else if (precedence.count(s[r])) {
          while (operatorStack.size() &&
                 precedence[operatorStack.back()] >= precedence[s[r]])
            f(valueStack, operatorStack);
          operatorStack.push_back(s[r]);
        }
        r++;
        l = r;
      }
    }

    if (r > l)
      valueStack.push_back(stoi(s.substr(l, r - l)));

    while (operatorStack.size())
      f(valueStack, operatorStack);

    return valueStack.back();
  }

  void f(vector<int> &valueStack, vector<char> &operatorStack) {

    char op = operatorStack.back();
    operatorStack.pop_back();
    int op2 = valueStack.back();
    valueStack.pop_back();
    int op1 = valueStack.back();
    valueStack.pop_back();

    if (op == '-')
      valueStack.push_back(op1 - op2);
    else if (op == '+')
      valueStack.push_back(op1 + op2);
    else if (op == '*')
      valueStack.push_back(op1 * op2);
    else if (op == '/')
      valueStack.push_back(op1 / op2);
  }
};
