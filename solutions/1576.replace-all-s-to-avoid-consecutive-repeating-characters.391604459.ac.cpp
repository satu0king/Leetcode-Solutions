class Solution {
public:
  string modifyString(string s) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '?') {
        vector<bool> allowed(256, true);
        if (i)
          allowed[s[i - 1]] = false;
        if (i + 1 < s.size())
          allowed[s[i + 1]] = false;
        for (char a = 'a'; a <= 'z'; a++)
          if (allowed[a]) {
            s[i] = a;
            break;
          }
      }
    }
    return s;
  }
};
