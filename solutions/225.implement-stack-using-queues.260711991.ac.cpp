class MyStack;

class MyStack {

  queue<void *> *q;

public:
  /** Initialize your data structure here. */
  MyStack() : q(NULL) {}

  /** Push element x onto stack. */
  void push(int x) {
    queue<void *> *tempQueue = new queue<void *>();
    int *y = new int;
    *y = x;
    tempQueue->push((void *)y);
    tempQueue->push((void *)q);
    q = tempQueue;
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int v = *(int *)q->front();
    q->pop();
    q = (queue<void *> *)q->front();
    return v;
  }

  /** Get the top element. */
  int top() { return *(int *)q->front(); }

  /** Returns whether the stack is empty. */
  bool empty() { return q == NULL; }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
