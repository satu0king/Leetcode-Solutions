class MyHashSet {
  vector<vector<int>> hashSet;
  int hash(int key) { return key % size; }

  int size;

public:
  /** Initialize your data structure here. */

  MyHashSet(int size = 100000) : size(size), hashSet(size) {}

  void add(int key) {
    if (!contains(key))
      hashSet[hash(key)].push_back(key);
  }

  void remove(int key) {
    for (auto i = hashSet[hash(key)].begin(); i != hashSet[hash(key)].end();
         i++)
      if (*i == key) {
        hashSet[hash(key)].erase(i);
        return;
      }
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    return find(hashSet[hash(key)].begin(), hashSet[hash(key)].end(), key) !=
           hashSet[hash(key)].end();
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
