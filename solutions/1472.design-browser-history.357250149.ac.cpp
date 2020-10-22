class BrowserHistory {
  vector<string> history;
  int ptr;

public:
  BrowserHistory(string homepage) {
    history.push_back(homepage);
    ptr = 1;
  }

  void visit(string url) {
    history.erase(history.begin() + ptr, history.end());
    history.push_back(url);
    ptr++;
  }

  string back(int steps) {
    ptr = max(1, ptr - steps);
    return history[ptr - 1];
  }

  string forward(int steps) {
    ptr = min((int)history.size(), ptr + steps);
    return history[ptr - 1];
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
