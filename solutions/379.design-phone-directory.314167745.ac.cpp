class PhoneDirectory {

  unordered_set<int> available;
  unordered_set<int> used;

public:
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone
     directory. */
  PhoneDirectory(int maxNumbers) {
    for (int i = 0; i < maxNumbers; i++)
      available.insert(i);
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (available.empty())
      return -1;
    int r = *available.begin();
    available.erase(r);
    used.insert(r);
    return r;
  }

  /** Check if a number is available or not. */
  bool check(int number) { return available.count(number); }

  /** Recycle or release a number. */
  void release(int number) {
    if (used.count(number)) {
      available.insert(number);
      used.erase(number);
    }
  }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
