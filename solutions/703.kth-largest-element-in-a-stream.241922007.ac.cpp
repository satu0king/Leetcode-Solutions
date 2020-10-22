class KthLargest {
  priority_queue<int, vector<int>, greater<int>> queue;
  int k;

public:
  KthLargest(int k, vector<int> &nums) : k(k) {
    for (auto n : nums) {
      queue.push(n);
      if (queue.size() > k)
        queue.pop();
    }
  }

  int add(int val) {
    queue.push(val);
    if (queue.size() > k)
      queue.pop();
    return queue.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
