class Solution {
public:
  int numSubmat(vector<vector<int>> &mat) {
    int ans = 0;
    int n = mat.size();
    int m = mat[0].size();
    vector<int> heights(m);
    for (int i = 0; i < n; i++) {
      stack<int> s;
      vector<int> count(m);
      for (int j = 0; j < m; j++) {
        if (mat[i][j])
          heights[j]++;
        else
          heights[j] = 0;

        while (s.size() && heights[s.top()] >= heights[j])
          s.pop();

        int w = j - (s.size() ? s.top() : -1);
        int h = heights[j];
        if (s.size())
          count[j] = count[s.top()];
        count[j] += h * w;
        ans += count[j];
        s.push(j);
      }
    }
    return ans;
  }
};
