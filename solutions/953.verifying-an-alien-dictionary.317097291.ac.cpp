class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {
    vector<char> inverseMap(256);
    for (int i = 0; i < 26; i++) {
      inverseMap[order[i]] = i + 'a';
    }

    for (auto &word : words) {
      for (auto &c : word) {
        c = inverseMap[c];
      }
    }

    for (int i = 1; i < words.size(); i++) {
      if (words[i] < words[i - 1])
        return false;
    }
    return true;
  }
};
