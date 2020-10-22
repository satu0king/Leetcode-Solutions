struct Sudoku {
  vector<vector<bool>> rows;
  vector<vector<bool>> cols;
  vector<vector<bool>> cells;
  vector<vector<char>> &board;

  Sudoku(vector<vector<char>> &board)
      : board(board), rows(9, vector<bool>(10)), cols(9, vector<bool>(10)),
        cells(9, vector<bool>(10)) {
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (board[i][j] != '.') {
          int v = board[i][j] - '0';
          insert(i, j, v);
        }
  }

  bool isValid(int i, int j, int v) {
    return !rows[i][v] && !cols[j][v] && !cells[(i / 3) * 3 + j / 3][v];
  }

  pair<int, int> findMissing() {
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (board[i][j] == '.')
          return make_pair(i, j);
    return make_pair(-1, -1);
  }

  void insert(int i, int j, int v) {
    rows[i][v] = true;
    cols[j][v] = true;
    cells[(i / 3) * 3 + j / 3][v] = true;
    board[i][j] = v + '0';
  }

  void remove(int i, int j, int v) {
    rows[i][v] = false;
    cols[j][v] = false;
    cells[(i / 3) * 3 + j / 3][v] = false;
    board[i][j] = '.';
  }
};

class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) {
    Sudoku s1(board);
    solve(s1);
  }

  bool solve(Sudoku &s1) {
    auto p = s1.findMissing();
    if (p.first == -1)
      return true;

    int i = p.first;
    int j = p.second;

    for (int k = 1; k <= 9; k++) {
      if (s1.isValid(i, j, k)) {
        // cout<<"HIT"<<endl;
        s1.insert(i, j, k);
        if (solve(s1))
          return true;
        s1.remove(i, j, k);
      }
    }

    return false;
  }
};
