class Solution {
public:
  int sumOfDigits(vector<int> &A) {
    int mn = *min_element(A.begin(), A.end());
    int s = 0;
    while (mn) {
      s += mn % 10;
      mn /= 10;
    }
    return s % 2 == 0;
  }
};
