class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &A,
                                           vector<vector<int>> &B) {
    int i = 0;
    int j = 0;
    int n1 = A.size();
    int n2 = B.size();
    vector<vector<int>> result;
    while (i < n1 && j < n2) {
      int r = min(A[i][1], B[j][1]);
      int l = max(A[i][0], B[j][0]);
      if (l <= r)
        result.push_back({l, r});

      if (A[i][1] < B[j][1])
        i++;
      else
        j++;
    }
    return result;
  }
};
