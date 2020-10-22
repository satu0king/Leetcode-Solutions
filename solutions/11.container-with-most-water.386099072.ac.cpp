class Solution {
public:
  int get(vector<int> arr) {
    int n = arr.size();
    vector<pair<int, int>> heights;

    int ans = 0;

    for (int i = n - 1; i >= 0; i--) {
      int l = 0, r = heights.size() - 1;
      int mid, cans = -1;
      while (l <= r) {
        mid = (l + r) / 2;
        if (heights[mid].first >= arr[i]) {
          cans = heights[mid].second;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }

      if (cans != -1)
        ans = max(ans, arr[i] * (cans - i));

      if (heights.empty() || heights.back().first < arr[i]) {
        heights.push_back({arr[i], i});
      }
    }
    return ans;
  }

  int maxArea(vector<int> &height) {
    int ans = get(height);
    reverse(height.begin(), height.end());
    ans = max(ans, get(height));
    return ans;
  }
};
