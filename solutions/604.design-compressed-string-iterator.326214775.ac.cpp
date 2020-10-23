class StringIterator {
  string s;
  int i;
  char c = ' ';
  int count = 0;

public:
  StringIterator(string compressedString) : s(compressedString), i(0) {
    _set();
  }

  void _set() {

    if (count > 0)
      return;

    if (i >= s.size()) {
      c = ' ';
      return;
    }

    while (count == 0 && i < s.size()) {
      c = s[i++];
      count = 0;
      while (i < s.size() && isdigit(s[i]))
        count = count * 10 + s[i++] - '0';
    }

    if (count == 0) {
      c = ' ';
    }
  }

  char next() {
    char r = c;
    count--;
    _set();
    return r;
  }

  bool hasNext() { return count > 0; }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
