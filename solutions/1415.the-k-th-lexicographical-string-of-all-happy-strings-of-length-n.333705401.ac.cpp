class Solution {
public:
  string getHappyString(int n, int k) {
    string s(n, 'a');
    for (int j = 1; j < n; j++) {
      if (s[j - 1] == 'a')
        s[j] = 'b';
      else
        s[j] = 'a';
    }
    k -= 1;
    while (k--)
      while (!getNext(s))
        return "";
    return s;
  }

  bool getNext(string &s) {
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {

      if (s[i] == 'a') {
        if (i == 0 || s[i - 1] != 'b') {
          s[i] = 'b';
          for (int j = i + 1; j < n; j++) {
            if (s[j - 1] == 'a')
              s[j] = 'b';
            else
              s[j] = 'a';
          }
          return true;
        }
        s[i] = 'c';
        s[i + 1] = 'a';
        for (int j = i + 2; j < n; j++) {
          if (s[j - 1] == 'a')
            s[j] = 'b';
          else
            s[j] = 'a';
        }
        return true;
      }
      if (s[i] == 'b' && (i == 0 || s[i - 1] != 'c')) {
        s[i] = 'c';
        s[i + 1] = 'a';
        for (int j = i + 2; j < n; j++) {
          if (s[j - 1] == 'a')
            s[j] = 'b';
          else
            s[j] = 'a';
        }
        return true;
      }
    }

    return false;
  }
};
