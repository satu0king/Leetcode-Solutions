class Solution {
public:
  string alphabetBoardPath(string target) {
    vector<pair<int, int>> positions;
    for (int i = 0; i < 26; i++)
      positions.emplace_back(i / 5, i % 5);

    string ans;
    char start = 'a';
    for (char c : target) {
      ans += path(start, c, positions);
      ans += '!';
      start = c;
    }

    return ans;
  }

  string path(char from, char to, vector<pair<int, int>> &positions) {
    if (from == to)
      return "";

    int x1 = positions[from - 'a'].first;
    int y1 = positions[from - 'a'].second;
    int x2 = positions[to - 'a'].first;
    int y2 = positions[to - 'a'].second;

    string result = "";

    if (x1 == 5) {
      result += 'U';
      x1--;
    } else if (x2 == 5) {
      while (y1) {
        result += 'L';
        y1--;
      }
    }

    while (x1 < x2) {
      result += 'D';
      x1++;
    }
    while (x1 > x2) {
      result += 'U';
      x1--;
    }
    while (y1 < y2) {
      result += 'R';
      y1++;
    }
    while (y1 > y2) {
      result += 'L';
      y1--;
    }

    return result;
  }
};
