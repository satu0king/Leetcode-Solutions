class Solution {
public:
  int minOperations(vector<string> &logs) {
    int c = 0;
    for (auto &l : logs) {
      l = l.substr(0, 2);
      if (l == "..")
        c--;
      else if (l != "./")
        c++;
      c = max(c, 0);
    }
    return c;
  }
};
