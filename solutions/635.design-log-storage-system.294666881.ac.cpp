
unordered_map<string, int> offset = {
    {"Year", 4},
    {"Month", 4 + 1 + 2},
    {"Day", 4 + 1 + 2 + 1 + 2},
    {"Hour", 4 + 1 + 2 + 1 + 2 + 1 + 2},
    {"Minute", 4 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2},
    {"Second", 4 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2}};

class LogSystem {
  multimap<string, int> logs;

public:
  LogSystem() {}

  void put(int id, string timestamp) { logs.emplace(timestamp, id); }

  vector<int> retrieve(string s, string e, string gra) {
    s = s.substr(0, offset[gra]);
    e = e.substr(0, offset[gra]);
    auto it1 = logs.lower_bound(s);
    auto it2 = logs.upper_bound(
        e + "z"); // Hack to get maximum date ending with this date.
    vector<int> result;
    while (it1 != it2)
      result.push_back((it1++)->second);
    return result;
  }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */
