class Solution {
public:
  vector<string> wordSubsets(vector<string> &A, vector<string> &B) {

    vector<int> temp(26);

    for (auto &s : B)
      temp = max1(temp, f1(s));
    vector<string> ans;

    for (auto &s : A)
      if (compare(temp, f1(s)))
        ans.push_back(s);

    return ans;
  }

  vector<int> f1(string &s) {
    vector<int> ans(26);
    for (char c : s)
      ans[c - 'a']++;
    return ans;
  }

  vector<int> max1(vector<int> v1, vector<int> v2) {
    vector<int> ans(26);
    for (int i = 0; i < 26; i++)
      ans[i] = max(v1[i], v2[i]);
    return ans;
  }

  bool compare(vector<int> v1, vector<int> v2) {
    for (int i = 0; i < 26; i++)
      if (v1[i] > v2[i])
        return false;
    return true;
  }
};
