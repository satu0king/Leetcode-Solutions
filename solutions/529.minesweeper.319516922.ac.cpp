class Solution {
public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
    int x = click[0];
    int y = click[1];
    if (board[x][y] == 'M') {
      board[x][y] = 'X';
      return board;
    }

    reveal(board, x, y);

    return board;
  }

  void reveal(vector<vector<char>> &board, int x, int y) {
    int n = board.size();
    int m = board[0].size();

    if (x < 0 || y < 0 || x >= n || y >= m)
      return;
    if (board[x][y] != 'E')
      return;

    int c = 0;

    for (int i = x - 1; i <= x + 1; i++)
      for (int j = y - 1; j <= y + 1; j++) {
        if (i < 0 || j < 0 || i >= n || j >= m)
          continue;
        if (board[i][j] == 'M')
          c++;
      }

    if (c) {
      board[x][y] = c + '0';
      return;
    }

    board[x][y] = 'B';

    for (int i = x - 1; i <= x + 1; i++)
      for (int j = y - 1; j <= y + 1; j++) {
        if (i == x && j == y)
          continue;
        reveal(board, i, j);
      }
  }
};
