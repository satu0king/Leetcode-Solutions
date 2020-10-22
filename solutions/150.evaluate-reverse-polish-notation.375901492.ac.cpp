class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> operandStack;
    for (auto &s : tokens) {
      if (s.size() != 1 || isdigit(s[0])) {
        operandStack.push(stoi(s));
      } else {
        int op2 = operandStack.top();
        operandStack.pop();
        int op1 = operandStack.top();
        operandStack.pop();
        if (s == "+")
          operandStack.push(op1 + op2);
        if (s == "-")
          operandStack.push(op1 - op2);
        if (s == "*")
          operandStack.push(op1 * op2);
        if (s == "/")
          operandStack.push(op1 / op2);
      }
    }
    return operandStack.top();
  }
};
