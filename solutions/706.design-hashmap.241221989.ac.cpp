class MyHashMap {

  vector<vector<pair<int, int>>> hashSet;
  int hash(int key) { return key % size; }

  int size;

public:
  /** Initialize your data structure here. */
  MyHashMap(int size = 100000) : size(size), hashSet(size) {}

  /** value will always be non-negative. */

  void put(int key, int value) {
    remove(key);
    hashSet[hash(key)].emplace_back(key, value);
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) {
    for (auto i : hashSet[hash(key)])
      if (i.first == key)
        return i.second;
    return -1;
  }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) {
    for (auto i = hashSet[hash(key)].begin(); i != hashSet[hash(key)].end();
         i++)
      if ((*i).first == key) {
        hashSet[hash(key)].erase(i);
        return;
      }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
