class Solution {
  vector<int> dp;

public:
  int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                     vector<int> &needs) {
    dp.resize(1e6, -1);
    return f(price, special, needs);
  }

  int f(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
    int key = hash(needs);
    if (~dp[key])
      return dp[key];

    int n = needs.size();
    int cost = 0;

    for (int j = 0; j < n; j++)
      cost += price[j] * needs[j];

    for (int i = 0; i < special.size(); i++) {
      bool flag = true;

      for (int j = 0; j < n; j++)
        if (needs[j] < special[i][j])
          flag = false;

      if (flag) {
        for (int j = 0; j < n; j++)
          needs[j] -= special[i][j];
        cost = min(cost, f(price, special, needs) + special[i][n]);
        for (int j = 0; j < n; j++)
          needs[j] += special[i][j];
      }
    }

    //         cost = min(cost, f(price, special, needs, i + 1));

    return dp[key] = cost;
  }

  int hash(vector<int> &v) {
    int h = 0;
    for (int c : v)
      h = h * 7 + c;
    return h;
  }
};
