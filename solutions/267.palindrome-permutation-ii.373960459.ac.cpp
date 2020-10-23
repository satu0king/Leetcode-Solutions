class Solution {
public:
  vector<string> generatePalindromes(string s) {
    unordered_map<char, int> mp;
    for (char c : s)
      mp[c]++;
    int oddCount = 0;
    char oddChar = -1;
    for (auto [c, count] : mp)
      if (count % 2) {
        oddChar = c;
        oddCount++;
      }
    if (oddCount > 1)
      return {};
    if (oddCount == 1) {
      mp[oddChar]--;
    }
    string a;
    for (auto [c, count] : mp)
      for (int i = 0; i < count; i += 2)
        a += c;
    vector<bool> visited(a.size());
    unordered_set<string> seen;
    string path;
    vector<string> ans;
    f(ans, path, seen, visited, a, oddChar);
    return ans;
  }
  void f(vector<string> &ans, string &path, unordered_set<string> &seen,
         vector<bool> &visited, string &arr, char oddChar) {
    if (seen.count(path))
      return;
    seen.insert(path);
    if (path.size() == arr.size()) {
      string t = path;
      if (~oddChar)
        t += oddChar;
      string t1 = path;
      reverse(t1.begin(), t1.end());
      t += t1;
      ans.push_back(t);
      return;
    }
    for (int i = 0; i < arr.size(); i++) {
      if (!visited[i]) {
        visited[i] = true;
        path += arr[i];
        f(ans, path, seen, visited, arr, oddChar);
        path.pop_back();
        visited[i] = false;
      }
    }
  }
};
