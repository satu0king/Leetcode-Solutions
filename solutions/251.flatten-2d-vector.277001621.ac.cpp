class Vector2D {
  int vectorIndex;
  int index;
  vector<vector<int>> &v;

public:
  Vector2D(vector<vector<int>> &v) : v(v) {
    vectorIndex = 0;
    index = 0;
    move();
  }

  int next() {
    int r = v[vectorIndex][index++];
    move();
    return r;
  }

  void move() {
    while (vectorIndex < v.size() && index == v[vectorIndex].size()) {
      index = 0;
      vectorIndex++;
    }
  }

  bool hasNext() { return vectorIndex != v.size(); }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
