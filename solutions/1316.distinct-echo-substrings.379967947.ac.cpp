const int p = 1e9 + 7;
struct RollingHash {
  vector<int> hash;
  vector<int> power;
  RollingHash(string &s) : hash(s.size() + 1), power(s.size() + 1, 1) {
    for (int i = 1; i <= s.size(); i++) {
      char c = s[i - 1];
      hash[i] = (hash[i - 1] * 257L + c) % p;
      power[i] = (power[i - 1] * 257L) % p;
    }
  }

  int getHash(int i, int j) {
    return (hash[j + 1] - ((long)power[j - i + 1] * hash[i]) % p + p) % p;
  }
};

class Solution {
public:
  int distinctEchoSubstrings(string text) {
    RollingHash hash(text);
    int n = text.size();
    int ans = 0;
    unordered_set<int> hashes;
    for (int i = 0; i < n; i++)
      for (int d = (n - i) / 2; d >= 1; d--) {
        int h1 = hash.getHash(i, i + d - 1);
        if (h1 == hash.getHash(i + d, i + 2 * d - 1)) {
          if (hashes.count(h1))
            break;
          hashes.insert(h1);
        }
      }

    return hashes.size();
  }
};
