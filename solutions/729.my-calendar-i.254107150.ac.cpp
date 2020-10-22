class MyCalendar {

  map<int, int> mp;

public:
  MyCalendar() {}

  bool book(int start, int end) {

    auto it1 = mp.lower_bound(start);

    if (it1 != mp.end() && it1->first == start)
      return false;

    if (it1 != mp.end() && it1->first < end)
      return false;

    if (mp.size() && it1 != mp.begin()) {
      --it1;
      if (it1->second > start)
        return false;
    }
    // return false;

    mp[start] = end;

    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
