class Solution {
public:
  int bitwiseComplement(int N) {
    int n = 1;

    while ((n & N) != N)
      n = 2 * n + 1;

    return n ^ N;
  }
};
