class Solution {
public:
  string reorderSpaces(string text) {
    vector<string> words;
    int spaceCount = 0;
    string prev;
    for (char c : text) {
      if (c == ' ') {
        spaceCount++;
        if (prev.size()) {
          words.push_back(prev);
          prev = "";
        }
      } else
        prev += c;
    }
    if (prev.size()) {
      words.push_back(prev);
      prev = "";
    }
    if (words.size() == 0)
      return text;
    if (words.size() == 1) {
      string ans = words[0];
      while (spaceCount--)
        ans += ' ';
      return ans;
    }
    int spaceInBetween = spaceCount / (words.size() - 1);
    string ans = words[0];
    for (int i = 1; i < words.size(); i++) {
      for (int j = 0; j < spaceInBetween; j++, spaceCount--)
        ans += ' ';
      ans += words[i];
    }

    while (spaceCount--)
      ans += ' ';
    return ans;
  }
};
