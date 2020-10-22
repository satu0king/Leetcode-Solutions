class Solution {
public:
  bool isPathCrossing(string path) {
    int x = 0, y = 0;
    unordered_map<int, unordered_set<int>> s;
    s[0].insert(0);
    for (char p : path) {
      if (p == 'N')
        y++;
      else if (p == 'S')
        y--;
      else if (p == 'E')
        x++;
      else
        x--;

      if (s[x].count(y))
        return true;
      else
        s[x].insert(y);
    }
    return false;
  }
};
