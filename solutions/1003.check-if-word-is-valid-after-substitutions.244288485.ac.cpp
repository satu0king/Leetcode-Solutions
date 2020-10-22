class Solution {

public:
  bool isValid(string S) {
    string s;

    for (char c : S) {
      s += c;
      while (s.size() >= 3 && s.substr(s.size() - 3, 3) == "abc") {
        s.pop_back();
        s.pop_back();
        s.pop_back();
      }
    }

    return s == "";
  }
};
