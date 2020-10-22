
bool check(vector<vector<char>> &board, int i, int j, int &ans) {
  if (board[i][j] == 'p') {
    ans++;
    return true;
  } else if (board[i][j] == 'B') {
    return true;
  }
  return false;
}

class Solution {
public:
  int numRookCaptures(vector<vector<char>> &board) {
    int i = 0;
    int j = 0;
    int n = board.size();
    int m = board[0].size();

    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (board[i][j] == 'R')
          break;
      }
      if (j < m && board[i][j] == 'R')
        break;
    }

    int ans = 0;
    for (int _i = i; _i < n; _i++) {
      if (check(board, _i, j, ans))
        break;
    }
    for (int _i = i; _i >= 0; _i--) {
      if (check(board, _i, j, ans))
        break;
    }
    for (int _j = j; _j < m; _j++) {
      if (check(board, i, _j, ans))
        break;
    }
    for (int _j = j; _j >= 0; _j--) {
      if (check(board, i, _j, ans))
        break;
    }
    return ans;
  }
};
