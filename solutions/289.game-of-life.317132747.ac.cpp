class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    int n = board.size();
    if (!n)
      return;
    int m = board[0].size();

    int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
    int dy[] = {1, -1, 1, -1, 0, -1, 1, 0};

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {

        int t = 0;

        for (int k = 0; k < 8; k++) {
          int new_i = i + dx[k];
          int new_j = j + dy[k];

          if (new_i < 0 || new_j < 0 || new_i >= n || new_j >= m)
            continue;

          t += board[new_i][new_j] == 1 || board[new_i][new_j] == -1;
        }

        if (t < 2 && board[i][j] == 1)
          board[i][j] = -1;
        else if (t > 3 && board[i][j] == 1)
          board[i][j] = -1;
        else if (t == 3 && board[i][j] == 0)
          board[i][j] = -2;
      }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (board[i][j] == -1)
          board[i][j] = 0;
        else if (board[i][j] == -2)
          board[i][j] = 1;
      }
  }
};
