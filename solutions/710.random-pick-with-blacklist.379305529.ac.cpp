class Solution {

  unordered_map<int, int> mp;
  int size;

public:
  Solution(int N, vector<int> &blacklist) {
    unordered_set<int> b(blacklist.begin(), blacklist.end());
    int blackListCount = 0;

    size = N - blacklist.size();
    int temp = N - 1;
    for (int a : blacklist)
      if (a < size) {
        while (b.count(temp))
          temp--;
        mp[a] = temp--;
      }
  }

  int pick() {
    int ans = rand() % size;
    if (mp.count(ans))
      ans = mp[ans];
    return ans;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
