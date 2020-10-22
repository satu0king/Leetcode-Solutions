class Solution {
public:
  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    unordered_set<string> hashSet;
    unordered_map<string, string> capSet;
    unordered_map<string, string> vowSet;
    reverse(wordlist.begin(), wordlist.end());
    for (string &w : wordlist) {
      hashSet.insert(w);
      string deCap = lower(w);
      capSet[deCap] = w;
      string deVow = deVowel(deCap);
      vowSet[deVow] = w;
    }
    vector<string> ans;
    for (auto &q : queries) {
      if (hashSet.count(q)) {
        ans.push_back(q);
        continue;
      }
      q = lower(q);
      if (capSet.count(q)) {
        ans.push_back(capSet[q]);
        continue;
      }
      q = deVowel(q);
      if (vowSet.count(q)) {
        ans.push_back(vowSet[q]);
        continue;
      }
      ans.push_back("");
    }
    return ans;
  }
  string deVowel(string s) {
    string vowels = "aeiou";
    for (char c : vowels)
      std::replace(s.begin(), s.end(), c, '*');
    return s;
  }
  string lower(string s) {
    for (char &c : s)
      c = tolower(c);
    return s;
  }
};
