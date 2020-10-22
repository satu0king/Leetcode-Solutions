class Solution {
public:
  int sumFourDivisors(vector<int> &nums) {
    int ans = 0;
    for (int a : nums)
      ans += isFour(a);
    return ans;
  }

  int isFour(int a) {
    int t = 2;
    int c = sqrt(a + 1);
    int s = 1 + a;
    for (int i = 2; i <= c; i++) {
      if (a % i == 0) {
        t++;
        s += i;
        if (a / i != i) {
          t++;
          s += a / i;
        }
      }
      if (t > 4)
        return 0;
    }
    // cout << a <<" " << t <<endl;
    return t == 4 ? s : 0;
  }
};
