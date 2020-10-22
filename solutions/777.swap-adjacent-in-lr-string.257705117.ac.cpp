class Solution {
public:
  bool canTransform(string start, string end) {
    vector<pair<char, int>> start_pos;
    vector<pair<char, int>> end_pos;

    int n = start.size();

    for (int i = 0; i < n; i++)
      if (start[i] != 'X')
        start_pos.emplace_back(start[i], i);

    for (int i = 0; i < n; i++)
      if (end[i] != 'X')
        end_pos.emplace_back(end[i], i);

    if (start_pos.size() != end_pos.size())
      return false;

    n = start_pos.size();

    for (int i = 0; i < n; i++) {
      auto p1 = start_pos[i];
      auto p2 = end_pos[i];
      if (p1.first != p2.first)
        return false;
      if (p1.first == 'L' && p1.second < p2.second)
        return false;
      if (p1.first == 'R' && p1.second > p2.second)
        return false;
    }

    return true;
  }
};
