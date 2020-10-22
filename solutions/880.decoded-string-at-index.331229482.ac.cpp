class Solution {
public:
  string decodeAtIndex(string S, int K) {

    long count = 0;

    for (char c : S) {
      if (isdigit(c))
        count *= c - '0';
      else
        count++;
    }

    for (int i = S.size() - 1; i >= 0; i--) {
      K %= count;
      if (K == 0 and isalpha(S[i]))
        return string(1, S[i]);

      if (isdigit(S[i]))
        count /= S[i] - '0';
      else
        count--;
    }

    return "";
  }
};
