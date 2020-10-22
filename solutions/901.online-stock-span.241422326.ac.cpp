class StockSpanner {

  vector<pair<int, int>> stack;
  int n;

public:
  StockSpanner() { n = 0; }

  int next(int price) {

    while (!stack.empty() && stack.back().first <= price)
      stack.pop_back();

    if (stack.empty()) {
      stack.emplace_back(price, n++);
      return n;
    }

    int j = stack.back().second;
    stack.emplace_back(price, n++);
    return n - j - 1;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
