class ZigzagIterator {
  queue<pair<vector<int>::iterator, vector<int>::iterator>> iteratorQueue;

public:
  ZigzagIterator(vector<int> &v1, vector<int> &v2) {
    if (v1.size())
      iteratorQueue.emplace(v1.begin(), v1.end());
    if (v2.size())
      iteratorQueue.emplace(v2.begin(), v2.end());
  }

  int next() {
    auto p = iteratorQueue.front();
    iteratorQueue.pop();
    int value = *p.first;
    if (++p.first != p.second)
      iteratorQueue.push(p);
    return value;
  }

  bool hasNext() { return !iteratorQueue.empty(); }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
