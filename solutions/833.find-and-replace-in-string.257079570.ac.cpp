class Solution {
public:
  string findReplaceString(string S, vector<int> &indexes,
                           vector<string> &sources, vector<string> &targets) {
    int n = sources.size();

    vector<int> id(n);
    for (int i = 0; i < n; i++)
      id[i] = i;

    auto cmp = [&indexes](int i, int j) { return indexes[i] > indexes[j]; };

    sort(id.begin(), id.end(), cmp);

    for (int i = 0; i < n; i++) {
      int n2 = S.size();
      int ind = indexes[id[i]];
      string &s = sources[id[i]];
      string &t = targets[id[i]];
      if (ind + s.size() <= n2) {
        if (S.substr(ind, s.size()) == s) {
          S = S.substr(0, ind) + t + S.substr(ind + s.size());
        }
      }
    }

    return S;
  }
};
