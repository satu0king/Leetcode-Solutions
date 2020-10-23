class Solution {
public:
  string nextClosestTime(string time) {
    unordered_set<char> allowed(time.begin(), time.end());
    int total = 24 * 60;
    int current = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
    while (1) {
      current = (current + 1) % total;

      string h = to_string(current / 60);
      string m = to_string(current % 60);
      if (h.size() == 1)
        h = "0" + h;
      if (m.size() == 1)
        m = "0" + m;

      string t = h + ":" + m;
      bool flag = true;
      for (char c : t)
        if (!allowed.count(c))
          flag = false;
      if (flag)
        return t;
    }
    return "";
  }
};
