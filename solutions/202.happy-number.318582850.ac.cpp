class Solution {
public:
  bool isHappy(int n) {
    int slowRunner = n;
    int fastRunner = n;

    do {
      slowRunner = next(slowRunner);
      fastRunner = next(next(fastRunner));
      if (slowRunner == 1)
        return true;
    } while (slowRunner != fastRunner);

    return false;
  }

  int next(int n) {
    int ans = 0;
    while (n) {
      int t = n % 10;
      n /= 10;
      ans += t * t;
    }
    return ans;
  }
};
