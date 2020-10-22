class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    vector<pair<int, char>> arr;
    unordered_map<char, int> temp;
    for (char t : tasks)
      temp[t]++;

    for (auto p : temp)
      arr.emplace_back(p.second, p.first);

    int ans = 0;
    int residual = 0;

    while (arr.size()) {
      sort(arr.begin(), arr.end());
      reverse(arr.begin(), arr.end());
      if (!arr[0].first)
        break;
      if (residual)
        ans += n + 1;
      residual = 0;
      for (int i = 0; i <= n && i < arr.size() && arr[i].first; i++) {
        arr[i].first--;
        residual++;
      }
    }

    return ans + residual;
  }
};
