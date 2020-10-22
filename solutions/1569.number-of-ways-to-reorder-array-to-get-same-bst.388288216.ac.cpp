
vector<vector<long>> score;
class Solution {

  const int p = 1e9 + 7;

public:
  int numOfWays(vector<int> &nums) {
    if (score.size() == 0) {
      score = vector<vector<long>>(1001, vector<long>(1001));
      score[0][0] = 1;
      for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++) {
          if (i)
            score[i][j] += score[i - 1][j];
          if (j)
            score[i][j] += score[i][j - 1];
          score[i][j] %= p;
        }
    }

    return (dfs(nums) - 1 + p) % p;
  }

  long dfs(vector<int> &nums) {
    if (nums.size() == 0)
      return 1;
    int root = nums[0];

    vector<int> left;
    vector<int> right;

    for (int a : nums)
      if (a < root)
        left.push_back(a);
      else if (a > root)
        right.push_back(a);

    long ans = (dfs(left) * dfs(right)) % p;
    ans = (ans * score[left.size()][right.size()]) % p;
    return ans;
  }
};
