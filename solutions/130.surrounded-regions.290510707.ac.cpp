int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class Solution {
public:
  void solve(vector<vector<char>> &board) {
    int n = board.size();
    if (!n)
      return;
    int m = board[0].size();

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
      if (board[i][0] == 'O')
        q.emplace(i, 0);
      if (board[i][m - 1] == 'O')
        q.emplace(i, m - 1);
    }

    for (int j = 1; j < m - 1; j++) {
      if (board[0][j] == 'O')
        q.emplace(0, j);
      if (board[n - 1][j] == 'O')
        q.emplace(n - 1, j);
    }

    while (q.size()) {
      auto p = q.front();
      q.pop();
      board[p.first][p.second] = 'Y';
      for (int k = 0; k < 4; k++) {
        int i = p.first + dx[k];
        int j = p.second + dy[k];
        if (i >= 0 && j >= 0 && i < n && j < m && board[i][j] == 'O') {
          board[i][j] = 'Y';
          q.emplace(i, j);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        else if (board[i][j] == 'Y')
          board[i][j] = 'O';
      }
    }
  }
};
