class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int N = flowerbed.size();
    for (int i = 0; i < N; i++) {
      if (!flowerbed[i]) {

        if (i > 0 && flowerbed[i - 1])
          continue;
        if (i < N - 1 && flowerbed[i + 1])
          continue;
        flowerbed[i] = 1;
        n--;
      }
    }

    return n <= 0;
  }
};
