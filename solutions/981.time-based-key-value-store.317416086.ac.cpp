class TimeMap {
public:
  /** Initialize your data structure here. */

  unordered_map<string, vector<pair<int, string>>> mp;
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    mp[key].emplace_back(timestamp, value);
  }

  string get(string key, int timestamp) {

    auto &m = mp[key];
    auto it = upper_bound(m.begin(), m.end(),
                          make_pair(timestamp, string("zzzzzzz")));
    if (it == m.begin())
      return "";
    return prev(it)->second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
