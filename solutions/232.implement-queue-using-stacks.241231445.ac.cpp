class MyQueue {
public:
  /** Initialize your data structure here. */

  vector<int> s1;
  vector<int> s2;
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { s1.push_back(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {

    int value = peek();
    if (~value)
      s2.pop_back();

    return value;
  }

  /** Get the front element. */
  int peek() {

    if (empty())
      return -1;

    if (s2.empty()) {
      while (s1.size()) {
        s2.push_back(s1.back());
        s1.pop_back();
      }
    }

    return s2.back();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return s1.empty() && s2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
