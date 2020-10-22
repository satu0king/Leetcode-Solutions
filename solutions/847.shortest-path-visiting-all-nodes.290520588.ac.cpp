struct Path {
  int last;
  int bitmask;
  int cost;
  Path() : last(0), bitmask(0), cost(0) {}
  void addPoint(int p, int c = 1) {
    last = p;
    cost += c;
    bitmask = bitmask | (1 << p);
  }
};

class Solution {
public:
  int shortestPathLength(vector<vector<int>> &graph) {
    queue<Path> pq;
    int n = graph.size();
    int mask = (1 << n) - 1;

    map<pair<int, int>, int> dist;

    for (int i = 0; i < n; i++) {
      Path path;
      path.addPoint(i, 0);
      pq.push(path);
      dist[make_pair(1 << i, 0)] = 0;
    }

    while (pq.size()) {
      auto path = pq.front();
      pq.pop();
      if (path.bitmask == mask)
        return path.cost;

      int u = path.last;

      for (auto v : graph[u]) {
        auto path2 = path;
        path2.addPoint(v);
        auto p = make_pair(path2.bitmask, path2.last);
        if (!dist.count(p) || dist[p] > path2.cost) {
          pq.push(path2);
          dist[make_pair(path2.bitmask, path2.last)] = path.cost;
        }
      }
    }

    return 0;
  }
};
