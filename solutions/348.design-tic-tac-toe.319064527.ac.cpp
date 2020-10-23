class TicTacToe {

  vector<int> cols;
  vector<int> rows;
  int diagonal;
  int antiDiagonal;
  int n;

public:
  /** Initialize your data structure here. */

  TicTacToe(int n) : diagonal(0), antiDiagonal(0), cols(n), n(n), rows(n) {}

  /** Player {player} makes a move at ({row}, {col}).
      @param row The row of the board.
      @param col The column of the board.
      @param player The player, can be either 1 or 2.
      @return The current winning condition, can be either:
              0: No one wins.
              1: Player 1 wins.
              2: Player 2 wins. */
  int move(int row, int col, int _player) {
    int player = _player * 2 - 3;

    cols[col] += player;
    rows[row] += player;

    if (row == col)
      diagonal += player;

    if (row + col == n - 1)
      antiDiagonal += player;

    if (abs(cols[col]) == n || abs(rows[row]) == n || abs(diagonal) == n ||
        abs(antiDiagonal) == n)
      return _player;

    return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
