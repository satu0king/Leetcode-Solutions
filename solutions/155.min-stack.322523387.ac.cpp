class MinStack {

  stack<int> s;
  stack<int> minStack;

public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    s.push(x);
    if (minStack.empty() || minStack.top() >= x)
      minStack.push(x);
  }

  void pop() {
    if (minStack.top() == s.top())
      minStack.pop();

    s.pop();
  }

  int top() { return s.top(); }

  int getMin() { return minStack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
