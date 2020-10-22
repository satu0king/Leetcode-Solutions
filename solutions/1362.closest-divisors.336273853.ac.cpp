class Solution {
public:
  vector<int> closestDivisors(int num) {
    int n1 = num + 1;
    int n2 = num + 2;
    vector<int> ans = {1, n1};
    int dif = n1 - 1;
    for (int i = 1; i * i <= n2; i++) {
      if (n1 % i == 0) {
        if (n1 / i - i < dif) {
          dif = n1 / i - i;
          ans = {i, n1 / i};
        }
      }
      if (n2 % i == 0) {
        if (n2 / i - i < dif) {
          dif = n2 / i - i;
          ans = {i, n2 / i};
        }
      }
    }

    return ans;
  }
};
