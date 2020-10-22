class Solution {
public:
  int maxCandies(vector<int> &status, vector<int> &candies,
                 vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
                 vector<int> &initialBoxes) {
    int n = status.size();
    vector<bool> foundClosed(n);
    queue<int> foundOpened;
    for (int i : initialBoxes) {
      if (status[i])
        foundOpened.push(i);
      else
        foundClosed[i] = true;
    }
    int ans = 0;
    while (foundOpened.size()) {
      int i = foundOpened.front();
      foundOpened.pop();
      ans += candies[i];
      for (int j : containedBoxes[i]) {
        if (status[j]) {
          foundOpened.push(j);
        } else {
          foundClosed[j] = true;
        }
      }
      for (int j : keys[i]) {
        if (status[j])
          continue;
        status[j] = 1;
        if (foundClosed[j]) {
          foundClosed[j] = false;
          foundOpened.push(j);
        }
      }
    }
    return ans;
  }
};
