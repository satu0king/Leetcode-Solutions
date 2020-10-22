class Solution {
public:
  string countOfAtoms(string formula) {
    int i = 0;
    auto mp = f(formula, i);
    string ans = "";
    for (auto [el, c] : mp) {
      ans += el;
      if (c > 1)
        ans += to_string(c);
    }
    return ans;
  }

  map<string, int> f(string &formula, int &i) {
    map<string, int> count;
    int n = formula.size();
    if (i == n)
      return count;
    while (i < n) {
      char c = formula[i];
      if (c == '(') {
        auto mp = f(formula, ++i);
        int multiplier = getNumber(formula, ++i);
        for (auto &[element, elementCount] : mp)
          count[element] += elementCount * multiplier;
      } else if (isupper(formula[i])) {
        int i0 = i++;
        while (i < n && islower(formula[i]))
          i++;
        string atom = formula.substr(i0, i - i0);
        count[atom] += getNumber(formula, i);
      } else
        break;
    }
    return count;
  }

  int getNumber(string &formula, int &i) {
    int multiplier = 0;
    int n = formula.size();
    if (i == n || !isdigit(formula[i])) {
      multiplier = 1;
    } else {
      while (i < n && isdigit(formula[i]))
        multiplier = multiplier * 10 + formula[i++] - '0';
    }
    return multiplier;
  }
};
