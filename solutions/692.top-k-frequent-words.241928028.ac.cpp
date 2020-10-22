struct struct1 {
  int count;
  string word;

  bool operator<(const struct1 &rhs) const {
    if (count != rhs.count)
      return count < rhs.count;
    return word > rhs.word;
  }
};

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {

    // auto compare1 = [](const pair<int, string> &p1, const pair<int, string>
    // &p2)  -> bool {
    //   if (p1.first!=p2.first)
    //       return p1.first < p2.first;
    //   return p1.second > p2.second;
    // };

    set<struct1> set;
    unordered_map<string, int> map;
    for (string &word : words)
      map[word]++;

    for (auto &p : map)
      set.insert({p.second, p.first});

    auto it = set.rbegin();
    vector<string> ans;
    while (k--)
      ans.push_back((it++)->word);
    return ans;
  }
};
