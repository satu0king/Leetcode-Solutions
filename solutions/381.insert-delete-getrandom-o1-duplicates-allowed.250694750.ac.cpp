class RandomizedCollection {
public:
  /** Initialize your data structure here. */

  unordered_map<int, unordered_set<int>> mp;
  vector<int> list;

  RandomizedCollection() {}

  /** Inserts a value to the collection. Returns true if the collection did not
   * already contain the specified element. */
  bool insert(int val) {
    bool ret = mp[val].empty();
    mp[val].insert(list.size());
    list.push_back(val);
    return ret;
  }

  /** Removes a value from the collection. Returns true if the collection
   * contained the specified element. */
  bool remove(int val) {
    if (mp[val].empty())
      return false;
    int i = *mp[val].begin();
    mp[val].erase(i);
    if (i == list.size() - 1)
      list.pop_back();
    else {
      int v = list.back();
      list.pop_back();
      mp[v].erase(list.size());
      mp[v].insert(i);
      list[i] = v;
    }

    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() {
    if (list.empty())
      return -1;
    return list[rand() % list.size()];
  }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
