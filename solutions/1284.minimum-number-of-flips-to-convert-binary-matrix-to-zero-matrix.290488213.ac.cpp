
int xy[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}};
class Solution {

public:
  int minFlips(vector<vector<int>> mat) {

    int ans = 0;
    queue<vector<vector<int>>> q;
    set<vector<vector<int>>> visited;
    visited.insert(mat);

    int n = mat.size();
    int m = mat[0].size();
    q.push(mat);

    while (q.size()) {
      int t = q.size();
      while (t--) {
        auto mat1 = q.front();
        q.pop();
        // if(visited.count(m))continue;
        bool flag = true;

        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++)
            if (mat1[i][j])
              flag = false;

        if (flag)
          return ans;

        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++) {

            vector<vector<int>> copy = mat1;
            for (int k = 0; k < 5; k++) {
              int ii = i + xy[k][0];
              int jj = j + xy[k][1];
              if (ii >= 0 && jj >= 0 && ii < n && jj < m) {
                copy[ii][jj] = (copy[ii][jj] + 1) % 2;
              }
            }
            if (!visited.count(copy)) {
              q.push(copy);
              visited.insert(copy);
            }
          }
      }
      ans++;
    }

    return -1;
  }
};
