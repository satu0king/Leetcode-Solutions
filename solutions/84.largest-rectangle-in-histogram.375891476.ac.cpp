class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> left(n);
    vector<int> right(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
      while (s.size() && heights[s.top()] >= heights[i])
        s.pop();
      left[i] = s.size() ? s.top() + 1 : 0;
      s.push(i);
    }
    s = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
      while (s.size() && heights[s.top()] >= heights[i])
        s.pop();
      right[i] = s.size() ? s.top() - 1 : n - 1;
      s.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, heights[i] * (right[i] - left[i] + 1));
    }
    return ans;
  }
};
