class HitCounter {
public:
  /** Initialize your data structure here. */
  int current = 0;
  queue<int> q;
  HitCounter() {}

  /** Record a hit.
      @param timestamp - The current timestamp (in seconds granularity). */
  void hit(int timestamp) {
    q.push(timestamp);
    current = timestamp;
    while (q.front() <= current - 300)
      q.pop();
  }

  /** Return the number of hits in the past 5 minutes.
      @param timestamp - The current timestamp (in seconds granularity). */
  int getHits(int timestamp) {
    current = timestamp;
    while (q.size() and q.front() <= current - 300)
      q.pop();
    return q.size();
  }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
