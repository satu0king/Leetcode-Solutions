class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &A) {
    int odd = 1;
    int even = 0;
    for (int i = 0; i < A.size(); i++) {

      // cout<<i<<" "<<odd<<" "<<even<<" "<<A[i] <<endl;
      if (i % 2 && i < odd)
        continue;
      if (i % 2 == 0 && i < even)
        continue;
      if (A[i] % 2) {
        swap(A[i], A[odd]);
        odd += 2;
      } else {
        swap(A[i], A[even]);
        even += 2;
      }
      i--;
    }
    return A;
  }

  void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
  }
};
