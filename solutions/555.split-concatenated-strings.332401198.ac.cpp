class Solution {
public:
  string splitLoopedString(vector<string> &strs) {
    int N = strs.size();
    vector<string> rstrs(N);

    for (int i = 0; i < N; i++) {
      string vstr = strs[i];

      reverse(vstr.begin(), vstr.end());

      if (vstr.compare(strs[i]) > 0) {
        rstrs[i] = strs[i];
        strs[i] = vstr;
      } else
        rstrs[i] = vstr;
    }

    string ans;

    for (int i = 0; i < N; i++) {
      for (auto str : {strs[i], rstrs[i]}) {
        for (int k = 0; k < str.length(); k++) {
          string t = str.substr(k);

          // Replacing strncmp with string::compare(), like
          //
          //   if (ans.compare(0, t.length(), t) > 0)
          //
          // will slow down the code, with runtime increased from
          // 68 ms to 248 ms.

          if (strncmp(ans.c_str(), t.c_str(), t.length()) > 0)
            continue;

          int off = min(ans.size(), t.size());

          for (int j = i + 1; j < N; j++) {
            t += strs[j];
            if (strncmp(ans.c_str() + off, t.c_str() + off, t.length() - off) >
                0)
              continue;

            off = min(ans.size(), t.size());
          }

          for (int j = 0; j < i; j++) {
            t += strs[j];
            if (strncmp(ans.c_str() + off, t.c_str() + off, t.length() - off) >
                0)
              continue;

            off = min(ans.size(), t.size());
          }

          t += str.substr(0, k);

          if (ans.compare(t) < 0)
            ans = t;
        }
      }
    }

    return ans;
  }
};
