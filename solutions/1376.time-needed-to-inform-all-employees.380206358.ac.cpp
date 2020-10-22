class Solution {
public:
  int n, headID;
  vector<int> manager, informTime;
  vector<int> dp;

  int f(int emp) {
    if (dp[emp] != -1)
      return dp[emp];
    if (manager[emp] != -1) {
      return dp[emp] = informTime[emp] + f(manager[emp]);
    } else {
      return dp[emp] = informTime[emp];
    }
  }

  int numOfMinutes(int n, int headID, vector<int> &manager,
                   vector<int> &informTime) {
    this->n = n;
    this->headID = headID;
    this->manager = manager;
    this->informTime = informTime;

    dp.assign(n, -1);
    int ans = -1;
    for (int i = 0; i < n; i++) {
      ans = max(ans, f(i));
    }
    return ans;
  }
};
