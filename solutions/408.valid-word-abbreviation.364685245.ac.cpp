class Solution {
public:
  bool validWordAbbreviation(string word, string abbr) {
    int i = 0;
    int c = 0;
    for (int j = 0; j < abbr.size(); j++) {
      if (isdigit(abbr[j])) {
        if (abbr[j] == '0' && c == 0)
          return false;
        c = c * 10 + abbr[j] - '0';
      } else {
        if (c) {
          i += c;
          c = 0;
        }
        if (i >= word.size())
          return false;
        if (word[i++] != abbr[j])
          return false;
      }
    }
    if (c) {
      i += c;
    }
    return i == word.size();
  }
};
