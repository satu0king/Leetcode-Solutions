class AllOne {
public:
  /** Initialize your data structure here. */
  unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> mp;
  list<pair<int, unordered_set<string>>> l;

  AllOne() {}

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1.
   */
  void inc(string key) {
    if (mp.count(key) == 0) {
      auto it = l.begin();
      if (it == l.end() || it->first != 1)
        l.emplace_front(1, unordered_set<string>{key});
      else
        it->second.insert(key);
      mp[key] = l.begin();
    } else {
      auto old_it = mp[key];
      old_it->second.erase(key);
      int old_value = old_it->first;
      auto new_it = next(old_it);
      if (new_it == l.end() || new_it->first != old_value + 1)
        l.emplace(new_it, old_value + 1, unordered_set<string>{key});
      else
        new_it->second.insert(key);
      new_it = next(old_it);
      mp[key] = new_it;

      if (old_it->second.empty())
        l.erase(old_it);
    }
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the
   * data structure. */
  void dec(string key) {
    if (mp.count(key)) {
      auto old_it = mp[key];
      old_it->second.erase(key);
      int old_value = old_it->first;
      if (old_value > 1) {
        auto new_it = prev(old_it);
        if (old_it == l.begin() || new_it->first != old_value - 1)
          l.emplace(old_it, old_value - 1, unordered_set<string>{key});
        else
          new_it->second.insert(key);
        new_it = prev(old_it);
        mp[key] = new_it;
      } else
        mp.erase(key);

      if (old_it->second.empty())
        l.erase(old_it);
    }
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    if (l.empty())
      return "";

    return *(l.back().second.begin());
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    if (l.empty())
      return "";
    return *(l.front().second.begin());
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
