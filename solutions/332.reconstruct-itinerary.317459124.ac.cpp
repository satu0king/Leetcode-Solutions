class Solution {

  unordered_map<string, vector<string>> g;
  vector<string> result;

public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    for (auto &trip : tickets)
      g[trip[0]].push_back(trip[1]);

    for (auto &p : g)
      sort(p.second.rbegin(), p.second.rend());

    visit("JFK");
    return vector<string>(result.rbegin(), result.rend());
  }

  void visit(string airport) {
    while (g[airport].size()) {
      string next = g[airport].back();
      g[airport].pop_back();
      visit(next);
    }
    result.push_back(airport);
  }
};
