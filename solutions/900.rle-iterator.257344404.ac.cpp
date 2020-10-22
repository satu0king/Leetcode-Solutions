class RLEIterator {
  vector<int> &A;
  int i;

public:
  RLEIterator(vector<int> &A) : A(A), i(0) {}

  int next(int n) {

    set();
    while (i < A.size()) {

      if (A[i] >= n) {
        int v = A[i + 1];
        A[i] -= n;
        return v;
      } else {
        n -= A[i];
        A[i] = 0;
        set();
      }
    }

    return -1;
  }

  void set() {
    while (i < A.size() && A[i] == 0)
      i += 2;
  }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
