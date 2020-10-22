class Solution {
public:
  int minFlipsMonoIncr(string S) {
    int n = S.size();
    int ones = count(S.begin(), S.end(), '1');
    int zeroes = n - ones;
    int ans = zeroes;

    int currentZeroes = 0;
    int currentOnes = 0;

    for (char c : S) {
      if (c == '1')
        currentOnes++;
      else
        currentZeroes++;

      ans = min(ans, currentOnes + zeroes - currentZeroes);
    }

    return ans;
  }
};
