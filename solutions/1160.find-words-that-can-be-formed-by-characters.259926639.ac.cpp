class Solution {
public:
  int countCharacters(vector<string> &words, string chars) {
    int sum = 0;
    auto v2 = f(chars);
    for (string &word : words)
      if (cmp(f(word), v2))
        sum += word.size();

    return sum;
  }

  vector<int> f(string &a) {
    vector<int> res(26);
    for (char c : a)
      res[c - 'a']++;
    return res;
  }

  bool cmp(vector<int> v1, vector<int> &v2) {
    for (int i = 0; i < 26; i++)
      if (v1[i] > v2[i])
        return false;
    return true;
  }
};
