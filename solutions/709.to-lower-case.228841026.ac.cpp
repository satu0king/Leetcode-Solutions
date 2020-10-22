class Solution {
public:
  string toLowerCase(string str) {
    for (auto &c : str) {
      if (c <= 'Z' && c >= 'A')
        c = c - 'A' + 'a';
    }
    return str;
  }
};
