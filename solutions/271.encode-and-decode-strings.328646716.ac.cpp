typedef unsigned char UCHAR;
class Codec {
public:
  // Encodes a list of strings to a single string.
  string encode(vector<string> &strs) {
    string result;
    for (auto &s : strs) {
      result += encode(s.size());
      result += s;
    }
    return result;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> ans;
    int i = 0;
    while (i < s.size()) {
      int len = decode(s, i);
      i += 4;
      ans.push_back(s.substr(i, len));
      i += len;
    }
    return ans;
  }

  string encode(int n) {
    string result(4, '0');
    int mask = 0xff;
    for (int i = 0; i < 4; i++)
      result[i] = (n >> (i * 8)) & mask;
    return result;
  }

  unsigned int decode(string &s, int j) {
    unsigned int ans = 0;
    for (int i = 0; i < 4; i++)
      ans += UCHAR(s[i + j]) << (i * 8);
    return ans;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
