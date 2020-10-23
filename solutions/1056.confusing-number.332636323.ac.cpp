
int mp[] = {0, 1, -1, -1, -1, -1, 9, -1, 9, 6};

class Solution {
public:
  bool confusingNumber(int N) {
    int temp = N;
    int newN = 0;
    while (temp) {
      if (~mp[temp % 10])
        newN = newN * 10 + mp[temp % 10];
      else
        return false;

      temp /= 10;
    }

    return newN != N;
  }
};
