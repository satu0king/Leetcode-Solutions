const int P = 1e9 + 7;

class Solution {
public:
  int findLength(vector<int> &A, vector<int> &B) {
    int n1 = A.size();
    int n2 = B.size();

    int l = 1;
    int r = min(n1, n2);
    int ans = 0;

    while (l <= r) {
      int mid = (l + r) / 2;
      if (f(A, B, mid)) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }

    return ans;
  }

  bool f(vector<int> &A, vector<int> &B, int len) {
    if (len == 0)
      return true;
    unordered_set<int> s1;
    long int hash = 0;
    long int h = 1;
    for (int i = 1; i < len; i++) {
      h = (h * 103) % P;
    }
    for (int i = 0; i < A.size(); i++) {
      if (i - len >= 0) {
        hash = (hash - (h * A[i - len]) % P + P) % P;
      }
      hash = (hash * 103 + A[i]) % P;
      if (i + 1 >= len) {
        s1.insert(hash);
      }
    }
    hash = 0;
    for (int i = 0; i < B.size(); i++) {
      if (i - len >= 0) {
        hash = (hash - (h * B[i - len]) % P + P) % P;
      }
      hash = (hash * 103 + B[i]) % P;
      if (i + 1 >= len && s1.count(hash))
        return true;
    }
    return false;
  }
};
