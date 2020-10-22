class Solution {
public:
  int brokenCalc(int X, int Y) {

    int ans = 0;
    while (Y > X) {
      if (Y % 2)
        Y++;
      else
        Y /= 2;
      ans++;
    }

    ans += X - Y;

    return ans;
  }
};
