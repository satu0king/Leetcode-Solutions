class Solution {
public:
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string, int> mp;
    for (auto &s : cpdomains) {
      int pos = s.find(' ');
      int val = stoi(s.substr(0, pos));

      mp[s.substr(++pos)] += val;

      while (pos < s.size()) {
        if (s[pos++] == '.')
          mp[s.substr(pos)] += val;
      }
    }

    vector<string> ans;
    for (auto &p : mp) {
      ans.push_back(to_string(p.second) + " " + p.first);
    }
    return ans;
  }
};
