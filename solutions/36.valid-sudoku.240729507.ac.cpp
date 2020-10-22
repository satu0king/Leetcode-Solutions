class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<vector<bool>> rows(9, vector<bool>(9)), cols(9, vector<bool>(9)),
        boxes(9, vector<bool>(9));

    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (board[i][j] != '.') {
          int c = board[i][j] - '0' - 1;
          int k = 3 * (i / 3) + j / 3;
          if (rows[i][c] || cols[j][c] || boxes[k][c])
            return false;
          rows[i][c] = true;
          cols[j][c] = true;
          boxes[k][c] = true;
        }

    return true;
  }
};
