class Solution {
public:
  string encode(int num) {

    num++;
    string s;
    while (num) {
      s += num % 2 + '0';
      num /= 2;
    }
    reverse(s.begin(), s.end());

    return s.substr(1);
  }
};

/*

001 -> 0
010 -> 1
011 -> 00
100 -> 01
101 -> 10
110 -> 11
111 -> 000

*/
