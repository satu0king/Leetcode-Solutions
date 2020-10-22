class Solution {
public:
  int maxRepOpt1(string text) {
    vector<int> count(256);
    for (char c : text)
      count[c]++;

    int ans = 0;
    int currentCount = 0;
    char prev = '*';
    vector<vector<pair<int, int>>> start(256);
    int n = text.size();
    for (int i = 0; i < text.size(); i++) {
      char c = text[i];
      if (prev == c)
        currentCount++;
      else {
        start[prev].emplace_back(i - currentCount, i - 1);
        currentCount = 1;
        prev = c;
      }

      ans = max(ans, min(currentCount + 1, count[c]));
    }

    start[prev].emplace_back(n - currentCount, n - 1);

    for (int c = 0; c < 256; c++) {
      for (int j = 1; j < start[c].size(); j++) {
        if (start[c][j - 1].second + 2 == start[c][j].first) {
          ans =
              max(ans, min(count[c],
                           start[c][j - 1].second - start[c][j - 1].first + 1 +
                               start[c][j].second - start[c][j].first + 1 + 1));
        }
      }
    }

    return ans;
  }
};
