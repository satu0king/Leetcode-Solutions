class Solution {
public:
  bool isValid(string s) {
    stack<char> bracketStack;

    unordered_map<char, char> closeOpenBracketMap = {
        {')', '('},
        {'}', '{'},
        {']', '['},
    };

    for (char c : s) {
      if (closeOpenBracketMap.count(c)) {
        if (bracketStack.size() && bracketStack.top() == closeOpenBracketMap[c])
          bracketStack.pop();
        else
          return false;
      } else
        bracketStack.push(c);
    }
    return bracketStack.empty();
  }
};
