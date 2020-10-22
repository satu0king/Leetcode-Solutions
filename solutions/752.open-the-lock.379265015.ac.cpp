class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    unordered_set<string> visited(deadends.begin(), deadends.end());
    string init = "0000";
    queue<string> bfs;

    if (visited.count(init))
      return -1;

    bfs.push(init);
    visited.insert(init);
    int res = 0;
    string temp, t;

    while (!bfs.empty()) {
      int sz = bfs.size();
      for (int i = 0; i < sz; i++) {
        t = bfs.front();
        bfs.pop();
        if (t == target)
          return res;
        for (int i = 0; i < 4; i++) {
          temp = t;
          temp[i] = (temp[i] - '0' + 1) % 10 + '0';
          if (visited.find(temp) == visited.end()) {
            bfs.push(temp);
            visited.insert(temp);
          }

          temp = t;
          temp[i] = (temp[i] - '0' + 9) % 10 + '0';
          if (visited.find(temp) == visited.end()) {
            bfs.push(temp);
            visited.insert(temp);
          }
        }
      }
      res++;
    }

    return -1;
  }
};
