class MyCalendarTwo {
private:
  map<int, int> ma;

public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    ma[start]++;
    ma[end]--;
    int total = 0;
    int maxi = 0;
    for (auto &e : ma) {
      total += e.second;
      maxi = max(maxi, total);
    }
    if (maxi >= 3) {
      ma[start]--;
      ma[end]++;
      return 0;
    }
    return 1;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
