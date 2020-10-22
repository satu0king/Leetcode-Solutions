class Solution {
public:
  int kthGrammar(int N, int K, int flip = 0) {
    if (N == 1)
      return flip;
    int len = 1 << (N - 1);
    if (K <= len / 2)
      return kthGrammar(N - 1, K, flip);
    return kthGrammar(N - 1, K - len / 2, flip ^ 1);
  }
};
