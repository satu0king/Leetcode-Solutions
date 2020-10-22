class Solution {
public:
  int smallestRepunitDivByK(int K) {
    vector<bool> visited(K);
    int candidate = 1;
    int ans = 1;
    while (candidate % K) {
      if (visited[candidate])
        return -1;
      visited[candidate] = true;
      candidate = candidate * 10 + 1;
      candidate %= K;
      ans++;
    }
    return ans;
  }
};
