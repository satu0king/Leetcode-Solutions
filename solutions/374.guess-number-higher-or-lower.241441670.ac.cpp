// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
    long long int l = 1;
    long long int r = n;
    while (l <= r) {
      long long int mid = (l + r) / 2;
      int g = guess(mid);
      if (g == 0)
        return mid;
      else if (g == -1)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return -1;
  }
};
