class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (dfs(board, word, i, j))
          return true;
    return false;
  }

  bool dfs(vector<vector<char>> &board, string &word, int i, int j, int l = 0) {
    int n = board.size();
    int m = board[0].size();
    if (l == word.size())
      return true;
    if (i < 0 || j < 0 || i >= n || j >= m)
      return false;
    if (board[i][j] != word[l])
      return false;

    char c = board[i][j];
    board[i][j] = '#';

    if (dfs(board, word, i + 1, j, l + 1) ||
        dfs(board, word, i - 1, j, l + 1) ||
        dfs(board, word, i, j + 1, l + 1) || dfs(board, word, i, j - 1, l + 1))
      return true;

    board[i][j] = c;
    return false;
  }
};
