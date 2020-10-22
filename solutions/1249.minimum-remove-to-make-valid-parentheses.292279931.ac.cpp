class Solution {
public:
  string minRemoveToMakeValid(string s) {
    int n = s.length();
    set<int> last_open;
    set<int> last_close;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        cnt++;
        last_open.insert(i);
      } else if (s[i] == ')') {
        last_close.insert(i);
        cnt--;
      }
      if (cnt < 0) {
        last_close.erase(*--last_close.end());
        cnt++;
      }
    }
    if (cnt > 0) {
      while (cnt != 0) {
        last_open.erase(*--last_open.end());
        cnt--;
      }
    }
    string p = "";
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        if (last_open.find(i) != last_open.end()) {
          p += s[i];
        } else {
          continue;
        }
      } else if (s[i] == ')') {
        if (last_close.find(i) != last_close.end()) {
          p += s[i];
        } else {
          continue;
        }
      } else {
        p += s[i];
      }
    }
    return p;
  }
};
