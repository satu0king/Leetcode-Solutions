class MaxStack {
  list<int> stack1;
  map<int, vector<list<int>::iterator>> sortedMap;

public:
  /** initialize your data structure here. */
  MaxStack() {}

  void push(int x) {
    stack1.push_back(x);
    sortedMap[x].push_back(prev(stack1.end()));
  }

  int pop() {
    int v = top();
    stack1.pop_back();
    sortedMap[v].pop_back();
    return v;
  }

  int top() { return stack1.back(); }

  int peekMax() {
    while (sortedMap.rbegin()->second.empty())
      sortedMap.erase(sortedMap.rbegin()->first);

    return sortedMap.rbegin()->first;
  }

  int popMax() {
    int v = peekMax();
    stack1.erase(sortedMap[v].back());
    sortedMap[v].pop_back();
    return v;
  }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
