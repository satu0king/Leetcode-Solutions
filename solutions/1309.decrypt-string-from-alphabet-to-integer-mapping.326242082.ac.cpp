class Solution {
public:
  string freqAlphabets(string s) {
    unordered_map<string, char> mp;
    for (int i = 1; i <= 9; i++)
      mp[to_string(i)] = 'a' + i - 1;

    for (int i = 10; i <= 26; i++)
      mp[to_string(i) + '#'] = 'j' + i - 10;

    string result = "";
    for (int i = 0; i < s.size(); i++) {
      if (i + 2 < s.size()) {
        auto t = s.substr(i, 3);
        if (mp.count(t)) {
          result += mp[t];
          i += 2;
          continue;
        }
      }
      result += mp[s.substr(i, 1)];
    }
    return result;
  }
};
