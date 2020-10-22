class ThroneInheritance {
  string kingName;
  unordered_map<string, vector<string>> g;
  unordered_set<string> dead;

public:
  ThroneInheritance(string kingName) : kingName(kingName) {}

  void birth(string parentName, string childName) {
    g[parentName].push_back(childName);
  }

  void death(string name) { dead.insert(name); }

  void dfs(vector<string> &ans, string &root) {
    if (!dead.count(root))
      ans.push_back(root);
    for (auto &child : g[root])
      dfs(ans, child);
  }

  vector<string> getInheritanceOrder() {
    vector<string> ans;
    dfs(ans, kingName);
    return ans;
  }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
