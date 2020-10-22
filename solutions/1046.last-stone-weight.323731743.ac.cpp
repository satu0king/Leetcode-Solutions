class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> pq;
    for (auto s : stones)
      pq.push(s);

    while (pq.size() > 1) {
      int stone1 = pq.top();
      pq.pop();
      int stone2 = pq.top();
      pq.pop();
      if (stone2 < stone1)
        pq.push(stone1 - stone2);
    }

    return pq.empty() ? 0 : pq.top();
  }
};
