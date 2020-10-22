class Solution {
public:
  int compress(vector<char> &chars) {
    int l = 0;
    int c = 1;

    for (int i = 1; i <= chars.size(); i++) {
      if (i == chars.size() || chars[i] != chars[i - 1]) {
        chars[l++] = chars[i - 1];
        if (c > 1)
          for (char j : to_string(c))
            chars[l++] = j;

        c = 1;
      } else
        c++;
    }

    return l;
  }
};
