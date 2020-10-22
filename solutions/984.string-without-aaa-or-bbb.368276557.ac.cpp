class Solution {
public:
  string strWithout3a3b(int A, int B) {
    char a = 'a';
    char b = 'b';
    if (A < B) {
      swap(A, B);
      swap(a, b);
    }
    string ans;
    while (A || B) {
      ans += a;
      A--;
      if (A > B) {
        ans += a;
        A--;
      }
      if (B) {
        ans += b;
        B--;
      }
    }
    return ans;
  }
};
