class Solution {
public:
  vector<string> printVertically(string s) {
    vector<string> ans;

    string t;
    stringstream inp(s);
    int j = 0;
    while (inp >> t) {
      int i = 0;
      for (char c : t) {
        if (ans.size() == i)
          ans.push_back("");
        ans[i] += string(j - ans[i].size(), ' ');
        ans[i++] += c;
      }
      j++;
    }
    return ans;
  }
};
