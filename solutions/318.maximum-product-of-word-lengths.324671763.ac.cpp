class Solution {
public:
  int maxProduct(vector<string> &words) {
    int n = words.size();
    vector<int> encodings(n);

    for (int i = 0; i < n; i++)
      for (char c : words[i])
        encodings[i] |= 1 << (c - 'a');

    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if ((encodings[i] & encodings[j]) == 0)
          ans = max(ans, (int)words[i].size() * (int)words[j].size());

    return ans;
  }

  inline int encode(string &w) {
    int code = 0;
    for (char c : w)
      code |= 1 << (c - 'a');
    return code;
  }
};
