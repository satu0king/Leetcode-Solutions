class Solution {
public:
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                   vector<int> &D) {
    unordered_map<int, int> AB;

    for (int i = 0; i < A.size(); i++)
      for (int j = 0; j < B.size(); j++)
        AB[A[i] + B[j]]++;
    int ans = 0;
    for (int i = 0; i < C.size(); i++)
      for (int j = 0; j < D.size(); j++)
        ans += AB[-C[i] - D[j]];
    return ans;
  }
};
