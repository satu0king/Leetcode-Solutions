class Solution {
public:
  string findLongestWord(string s, vector<string> &d) {
    string ans = "";

    for (string &w : d) {
      if (w.size() >= ans.size() && isSubsequence(w, s)) {
        if (w.size() > ans.size())
          ans = w;
        else if (w < ans)
          ans = w;
      }
    }

    return ans;
  }

  bool isSubsequence(string &s1, string &s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    int i = 0;
    int j = 0;

    while (i < n1 && j < n2) {
      if (s1[i] == s2[j]) {
        i++;
        j++;
      } else
        j++;
    }

    return i == n1;
  }
};
