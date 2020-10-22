const long P = 1e9 + 7;
const long m = 257;

class Solution {
public:
  string shortestPalindrome(string s) {

    long hash1 = 0;
    long hash2 = 0;
    long h = 1;
    int t = 0;
    for (int i = 0; i < s.size(); i++, h = (h * m) % P) {
      hash1 = (hash1 * m + s[i]) % P;
      hash2 = (hash2 + s[i] * h) % P;
      if (hash1 == hash2)
        t = i + 1;
    }
    string temp = s.substr(t);
    reverse(temp.begin(), temp.end());
    return temp + s;
  }
};
