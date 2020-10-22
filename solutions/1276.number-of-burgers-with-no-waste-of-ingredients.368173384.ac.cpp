class Solution {
public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    int jumbo = (tomatoSlices - 2 * cheeseSlices) / 2;
    int small = cheeseSlices - jumbo;
    if (4 * jumbo + 2 * small != tomatoSlices || jumbo < 0 || small < 0)
      return {};
    return {jumbo, small};
  }
};

// x - jumbo
// y - small

// 2x + 2y = 2 * cheese
// 4x + 2y = tomato

// 2x = tomato - 2 * cheese
