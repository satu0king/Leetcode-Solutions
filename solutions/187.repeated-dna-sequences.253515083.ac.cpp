class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    if (s.size() < 10)
      return ans;

    unordered_map<long long int, int> map;
    unordered_map<char, int> encode = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
    long long int h = 1;
    long long int p = 1e9 + 7;
    long long int hash = 0;
    for (int i = 0; i < 10; i++) {
      hash = (hash * 5 + encode[s[i]]) % p;
      if (i)
        h = (h * 5) % p;
    }

    map[hash] = 1;

    for (int i = 10; i < s.size(); i++) {
      hash = (hash - h * (encode[s[i - 10]]) + p) % p;
      hash = (hash * 5 + encode[s[i]]) % p;
      if (map[hash]++ == 1)
        ans.push_back(s.substr(i - 10 + 1, 10));
    }

    return ans;
  }
};
