class Solution {
public:
  string rearrangeString(string s, int k) {

    unordered_map<char, int> mp;
    for (char c : s)
      mp[c]++;

    priority_queue<pair<int, char>> pq;

    for (auto [c, v] : mp)
      pq.emplace(v, c);

    string ans;

    while (pq.size()) {
      vector<pair<int, char>> pq_next;
      int t = max(1, k);

      while (pq.size() && t > 0) {
        t--;
        auto [v, c] = pq.top();
        pq.pop();
        ans += c;
        if (--v)
          pq_next.emplace_back(v, c);
      }

      if (t && pq_next.size())
        return "";

      for (auto p : pq_next)
        pq.push(p);
    }

    return ans;
  }
};
