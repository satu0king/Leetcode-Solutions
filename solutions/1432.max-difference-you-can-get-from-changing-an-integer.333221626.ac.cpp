class Solution {
public:
  int maxDiff(int num) {
    string s = to_string(num);
    auto a = getMaxString(s);
    auto b = getMinString(s);

    return stoi(a) - stoi(b);
  }

  string getMaxString(string s) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '9') {
        for (int j = i + 1; j < s.size(); j++)
          if (s[j] == s[i])
            s[j] = '9';
        s[i] = '9';
        return s;
      }
    }
    return s;
  }

  string getMinString(string s) {

    if (s[0] != '1') {
      for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[0])
          s[i] = '1';
      }
      s[0] = '1';
      return s;
    }

    for (int i = 1; i < s.size(); i++) {
      if (s[i] != '0' && s[i] != '1') {
        for (int j = i + 1; j < s.size(); j++)
          if (s[j] == s[i])
            s[j] = '0';
        s[i] = '0';
        return s;
      }
    }
    return s;
  }
};
