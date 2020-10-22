class SubrectangleQueries {
  vector<vector<int>> r;
  deque<tuple<int, int, int, int, int>> updates;

public:
  SubrectangleQueries(vector<vector<int>> &rectangle) : r(rectangle) {}

  void updateSubrectangle(int row1, int col1, int row2, int col2,
                          int newValue) {
    updates.emplace_front(row1, col1, row2, col2, newValue);
  }

  int getValue(int row, int col) {
    for (auto &u : updates) {
      auto [row1, col1, row2, col2, newValue] = u;
      if (row1 <= row && row <= row2 && col1 <= col && col <= col2)
        return newValue;
    }
    return r[row][col];
  }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
