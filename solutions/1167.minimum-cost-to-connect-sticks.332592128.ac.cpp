class Solution {
public:
  int connectSticks(vector<int> &sticks) {
    priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(),
                                                      sticks.end());
    int result = 0;
    while (pq.size() > 1) {
      int m1 = pq.top();
      pq.pop();
      int m2 = pq.top();
      pq.pop();
      result += m1 + m2;
      pq.push(m1 + m2);
    }

    return result;
  }
};
