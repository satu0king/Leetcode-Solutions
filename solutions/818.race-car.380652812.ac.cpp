class Solution {
public:
  int racecar(int target) {
    int d = 2 * target;
    queue<pair<int, int>> q;
    unordered_map<int, unordered_set<int>> visited;
    int ans = 0;
    visited[0].insert(1);
    q.push({0, 1});

    while (q.size()) {
      int z = q.size();
      while (z--) {
        auto [pos, speed] = q.front();
        q.pop();
        if (pos == target)
          return ans;
        if (pos + speed >= 0 && pos + speed <= d &&
            !visited[pos + speed].count(speed * 2)) {
          q.push({pos + speed, speed * 2});
          visited[pos + speed].insert(speed * 2);
        }

        int oppDir = speed > 0 ? -1 : 1;
        if (!visited[pos].count(oppDir)) {
          q.push({pos, oppDir});
          visited[pos].insert(oppDir);
        }
      }
      ans++;
    }

    return -1;
  }
};
