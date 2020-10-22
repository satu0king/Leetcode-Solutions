class LRUCache {

  list<int> lru;
  unordered_map<int, int> keyValueMap;
  unordered_map<int, list<int>::iterator> keyListIteratorMap;
  int capacity;

public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (!keyValueMap.count(key))
      return -1;

    lru.erase(keyListIteratorMap[key]);
    lru.push_front(key);
    keyListIteratorMap[key] = lru.begin();

    return keyValueMap[key];
  }

  void put(int key, int value) {

    if (keyValueMap.count(key)) {
      lru.erase(keyListIteratorMap[key]);
      lru.push_front(key);
      keyListIteratorMap[key] = lru.begin();
      keyValueMap[key] = value;
      return;
    }

    if (lru.size() == capacity) {
      int evictedKey = lru.back();
      lru.erase(keyListIteratorMap[evictedKey]);
      keyListIteratorMap.erase(evictedKey);
      keyValueMap.erase(evictedKey);
    }

    lru.push_front(key);
    keyListIteratorMap[key] = lru.begin();
    keyValueMap[key] = value;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
