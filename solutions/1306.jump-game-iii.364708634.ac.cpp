class Solution {
public:
  bool canReach(vector<int> &arr, int start) {
    int n = arr.size();
    vector<bool> visited(n);
    vector<int> q = {start};
    visited[start] = true;
    while (q.size()) {
      int i = q.back();
      q.pop_back();
      if (arr[i] == 0)
        return true;
      if (i + arr[i] < n && !visited[i + arr[i]]) {
        visited[i + arr[i]] = true;
        q.push_back(i + arr[i]);
      }
      if (i - arr[i] >= 0 && !visited[i - arr[i]]) {
        visited[i - arr[i]] = false;
        q.push_back(i - arr[i]);
      }
    }

    return false;
  }
};
