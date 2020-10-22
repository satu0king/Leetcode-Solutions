
// Range Max Query
struct SegmentTree {
  vector<int> tree;
  vector<int> lazy;
  int n;
  SegmentTree(int n) : n(n) {
    int size = 1;
    while (size <= n)
      size *= 2;
    size *= 2;
    tree.resize(size);
    lazy.resize(size);
  }

  int combine(int l, int r) { return max(l, r); }

  void pushDown(int id) {
    if (!lazy[id])
      return;
    lazy[2 * id] = lazy[id];
    lazy[2 * id + 1] = lazy[id];
    tree[2 * id] = lazy[id];
    tree[2 * id + 1] = lazy[id];
    lazy[id] = 0;
  }

  int get(int id, int tl, int tr, int l, int r) {
    if (l > r)
      return INT_MIN;
    if (tl == l && tr == r)
      return tree[id];
    pushDown(id);
    int treeMid = (tl + tr) / 2;
    int lValue = get(id * 2, tl, treeMid, l, min(treeMid, r));
    int rValue = get(id * 2 + 1, treeMid + 1, tr, max(l, treeMid + 1), r);
    return combine(lValue, rValue);
  }

  int get(int l, int r) { return get(1, 0, n - 1, l, r); }

  void update(int id, int tl, int tr, int l, int r, int value) {
    if (l > r)
      return;
    if (tl == l && tr == r) {
      tree[id] = value;
      lazy[id] = value;
      return;
    }
    pushDown(id);
    int treeMid = (tl + tr) / 2;
    update(id * 2, tl, treeMid, l, min(treeMid, r), value);
    update(id * 2 + 1, treeMid + 1, tr, max(l, treeMid + 1), r, value);
    tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
  }

  void update(int l, int r, int value) { update(1, 0, n - 1, l, r, value); }
  void update(int i, int value) { update(i, i, value); }
};

class Solution {
public:
  vector<int> fallingSquares(vector<vector<int>> &positions) {
    vector<int> temp;
    for (auto &v : positions) {
      temp.push_back(v[0]);
      temp.push_back(v[0] + v[1]);
    }
    sort(temp.begin(), temp.end());
    temp.resize(std::distance(temp.begin(), unique(temp.begin(), temp.end())));

    unordered_map<int, int> mp;
    mp.reserve(temp.size());
    for (int i = 0; i < temp.size(); i++)
      mp[temp[i]] = i;

    vector<int> heights(temp.size());
    SegmentTree segmentTree(temp.size());
    temp.clear();

    vector<int> ans;
    for (auto &v : positions) {

      int start = mp[v[0]];
      int end = mp[v[0] + v[1]];
      int h = segmentTree.get(start, end - 1) + v[1];

      segmentTree.update(start, end - 1, h);

      if (ans.size() && ans.back() > h)
        h = ans.back();

      ans.push_back(h);
    }

    return ans;
  }
};

// [1, 1] = 2
// [2, 4] = 5
