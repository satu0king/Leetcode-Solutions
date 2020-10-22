class Solution {
public:
  int scoreOfParentheses(string S) {

    vector<int> stack1;

    for (char c : S) {
      if (c == '(')
        stack1.push_back(-1);
      else {
        int sum = 0;
        while (stack1.back() != -1) {
          sum += stack1.back();
          stack1.pop_back();
        }
        stack1.pop_back();
        stack1.push_back(max(1, 2 * sum));
      }
    }

    int sum = 0;
    while (stack1.size()) {
      sum += stack1.back();
      stack1.pop_back();
    }
    return sum;
  }
};
