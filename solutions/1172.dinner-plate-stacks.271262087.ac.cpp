class DinnerPlates {
  int capacity;
  vector<stack<int>> stacks;
  set<int> stacksWithSpace;

public:
  DinnerPlates(int capacity) : capacity(capacity), stacks(1) {
    stacksWithSpace.insert(0);
  }

  void push(int val) {
    int i = *stacksWithSpace.begin();
    stacks[i].push(val);
    if (stacks[i].size() == capacity) {
      stacksWithSpace.erase(i);
      if (stacks.size() == i + 1) {
        stacksWithSpace.insert(i + 1);
        stacks.push_back(stack<int>());
      }
    }
  }

  int pop() {
    while (stacks.size() && stacks.back().empty())
      stacks.pop_back();

    int ans = -1;

    if (stacks.size()) {
      ans = stacks.back().top();
      stacks.back().pop();
      stacksWithSpace.insert(stacks.size() - 1);
    }

    if (stacks.empty())
      stacks.push_back(stack<int>());

    return ans;
  }

  int popAtStack(int index) {
    if (index >= stacks.size() || stacks[index].empty())
      return -1;
    int p = stacks[index].top();
    stacks[index].pop();
    stacksWithSpace.insert(index);
    return p;
  }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
