class CustomStack {
  stack<int> s;
  vector<int> increments;
  int maxSize;

public:
  CustomStack(int maxSize) : increments(maxSize + 1), maxSize(maxSize) {}

  void push(int x) {
    if (s.size() < maxSize) {
      s.push(x);
    }
  }

  int pop() {
    int size = s.size();
    if (!size)
      return -1;
    int p = s.top();
    s.pop();
    p += increments[size];
    increments[size - 1] += increments[size];
    increments[size] = 0;
    return p;
  }

  void increment(int k, int val) { increments[min(k, (int)s.size())] += val; }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
