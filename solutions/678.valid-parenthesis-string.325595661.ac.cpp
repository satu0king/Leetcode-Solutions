class Solution {
public:
  bool checkValidString(string s) {

    if (!f(s))
      return false;
    reverse(s.begin(), s.end());
    for (char &c : s)
      if (c == '(')
        c = ')';
      else if (c == ')')
        c = '(';

    return f(s);
  }

  bool f(string s) {

    int open = 0;
    int star = 0;
    for (char c : s) {
      if (c == '(')
        open++;
      else if (c == ')') {
        if (open)
          open--;
        else if (star)
          star--;
        else
          return false;
      } else if (c == '*')
        star++;
    }

    return true;
  }
};
