class Solution {
  unordered_map<int, string> dp;

public:
  string largestNumber(vector<int> &cost, int target) {
    return f(cost, target);
  }

  string f(vector<int> &cost, int target) {
    if (target < 0)
      return "0";
    if (target == 0)
      return "";
    if (dp.count(target))
      return dp[target];

    string best = "0";

    for (int i = 0; i < 9; i++) {
      auto temp = f(cost, target - cost[i]);
      if (temp != "0") {
        temp = string(1, '1' + i) + temp;
        if (temp.size() > best.size())
          best = temp;
        else if (temp.size() == best.size())
          best = max(best, temp);
      }
    }

    return dp[target] = best;
  }
};
