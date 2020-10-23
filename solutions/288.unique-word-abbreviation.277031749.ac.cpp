class ValidWordAbbr {
  unordered_map<string, unordered_set<string>> abbreviations;

public:
  ValidWordAbbr(vector<string> &dictionary) {
    for (string &word : dictionary)
      abbreviations[abbreviate(word)].insert(word);
  }

  string abbreviate(string &w) {
    if (w.size() <= 2)
      return w;
    string ans = "";
    ans += w[0];
    ans += to_string(w.size() - 2);
    ans += w[w.size() - 1];
    return ans;
  }

  bool isUnique(string word) {
    return abbreviations[abbreviate(word)].empty() ||
           (abbreviations[abbreviate(word)].size() == 1 &&
            *abbreviations[abbreviate(word)].begin() == word);
  }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
