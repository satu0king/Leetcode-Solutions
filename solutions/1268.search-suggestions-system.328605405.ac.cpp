
class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string>> res;
    string pat = "";
    auto it = products.begin();
    for (char c : searchWord) {
      pat += c;
      vector<string> step;
      it = lower_bound(it, products.end(), pat);
      for (int i = 0; i < 3; i++) {
        if (it + i == products.end())
          break;
        string &n = *(it + i);
        if (pat != n.substr(0, pat.size()))
          break;
        step.push_back(n);
      }
      res.push_back(step);
    }
    return res;
  }
};
