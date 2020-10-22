class Solution {
public:
  bool hasAlternatingBits(int n) {

    bool isOdd = n % 2;

    while (n) {
      if ((n % 2 == 1 && !isOdd) || (n % 2 == 0 && isOdd))
        return false;
      n >>= 1;
      isOdd = !isOdd;
    }

    return true;
  }
};
