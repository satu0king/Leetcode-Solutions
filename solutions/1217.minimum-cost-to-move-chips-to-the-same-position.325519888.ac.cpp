class Solution {
public:
  int minCostToMoveChips(vector<int> &chips) {

    int odd = 0;
    int even = 0;
    for (int a : chips)
      if (a % 2)
        odd++;
      else
        even++;
    return min(odd, even);
  }
};
