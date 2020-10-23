class Solution {
public:
  bool validWordSquare(vector<string> &words) {
    int n = words.size();
    if (!n)
      return true;
    int m = words[0].size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < words[i].size(); j++)
        if (j == n || words[j].size() == i || words[i][j] != words[j][i])
          return false;
    return true;
  }
};
