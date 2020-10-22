class RandomizedSet {
  vector<int> elements;
  unordered_map<int, int> mp;

public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (mp.count(val))
      return false;
    mp[val] = elements.size();
    elements.push_back(val);

    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (!mp.count(val))
      return false;

    int t = elements.back();
    mp[t] = mp[val];
    elements[mp[val]] = t;

    elements.pop_back();

    mp.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    if (elements.empty())
      return -1;

    return elements[rand() % elements.size()];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
