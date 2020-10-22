class Solution {
public:
  int minOperationsMaxProfit(vector<int> &customers, int boardingCost,
                             int runningCost) {
    int ans = -1;
    int score = 0;
    int maxScore = -1;
    int waiting = 0;
    int r = 0;
    for (int c : customers) {
      r++;
      waiting += c;
      int board = min(waiting, 4);
      waiting -= board;
      score += board * boardingCost - runningCost;
      if (score > maxScore) {
        maxScore = score;
        ans = r;
      }
    }
    while (waiting) {
      r++;
      int board = min(waiting, 4);
      waiting -= board;
      score += board * boardingCost - runningCost;
      if (score > maxScore) {
        maxScore = score;
        ans = r;
      }
    }
    return ans;
  }
};
