class Solution {
public:
  int dietPlanPerformance(vector<int> &calories, int k, int lower, int upper) {
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < k; i++)
      sum += calories[i];

    if (sum < lower)
      ans--;
    else if (sum > upper)
      ans++;

    for (int i = k; i < calories.size(); i++) {
      sum -= calories[i - k];
      sum += calories[i];
      if (sum < lower)
        ans--;
      else if (sum > upper)
        ans++;
    }
    return ans;
  }
};
