class Solution {
public:
  vector<int> pancakeSort(vector<int> &A) {
    int n = A.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int mx = 0;
      for (int j = 0; j < n - i; j++)
        if (A[j] > A[mx])
          mx = j;
      ans.push_back(++mx);
      ans.push_back(n - i);
      reverse(A.begin(), A.begin() + mx);
      reverse(A.begin(), A.begin() + n - i);
    }

    return ans;
  }
};
