class Solution {
public:
  string tictactoe(vector<vector<int>> &moves) {
    vector<string> game(3, string(3, ' '));
    char c;
    for (int i = 0; i < moves.size(); i++) {
      move(game, moves, i);
      // c = check(game);
      // if(c == 'A')return "A";
      // else if(c == 'B')return "B";
    }
    c = check(game);
    if (c == 'D') {
      if (moves.size() == 9)
        return "Draw";
      return "Pending";
    } else if (c == 'A')
      return "A";
    else if (c == 'B')
      return "B";
    return "";
  }

  void move(vector<string> &game, vector<vector<int>> &moves, int i) {
    char c = i % 2 ? 'B' : 'A';
    game[moves[i][0]][moves[i][1]] = c;
  }

  char check(vector<string> &game) {
    for (int i = 0; i < 3; i++) {
      if (game[i][0] != ' ' && game[i][0] == game[i][1] &&
          game[i][1] == game[i][2])
        return game[i][0];

      if (game[0][i] != ' ' && game[0][i] == game[1][i] &&
          game[1][i] == game[2][i])
        return game[0][i];
    }

    if (game[0][0] != ' ' && game[0][0] == game[1][1] &&
        game[1][1] == game[2][2])
      return game[0][0];

    if (game[2][0] != ' ' && game[2][0] == game[1][1] &&
        game[1][1] == game[0][2])
      return game[2][0];

    return 'D';
  }
};
