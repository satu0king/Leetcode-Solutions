class LFUCache {

  int capacity;
  int minFreq;

  unordered_map<int, int> valueMap;
  unordered_map<int, int> freqMap;
  unordered_map<int, list<int>::iterator> iteratorMap;
  unordered_map<int, list<int>> freqKeyMap;

public:
  LFUCache(int capacity) : capacity(capacity), minFreq(1) {}

  int get(int key) {
    if (valueMap.count(key)) {
      increaseFreq(key);
      return valueMap[key];
    }

    return -1;
  }

  void put(int key, int value) {
    if (capacity == 0)
      return;
    if (!valueMap.count(key)) {

      if (valueMap.size() == capacity) {
        auto it = freqKeyMap[minFreq].begin();
        int key = *it;

        freqKeyMap[minFreq].erase(it);
        valueMap.erase(key);
        freqMap.erase(key);
        iteratorMap.erase(key);

        if (freqKeyMap[minFreq].empty()) {
          freqKeyMap.erase(minFreq);
        }
      }

      minFreq = 1;

      valueMap[key] = value;
      freqMap[key] = 1;
      freqKeyMap[1].push_back(key);
      iteratorMap[key] = prev(freqKeyMap[1].end());
    } else {
      increaseFreq(key);
      valueMap[key] = value;
    }
  }

  void increaseFreq(int key) {
    int oldFreq = freqMap[key];
    int newFreq = oldFreq + 1;

    freqKeyMap[oldFreq].erase(iteratorMap[key]);
    if (freqKeyMap[oldFreq].empty()) {
      freqKeyMap.erase(oldFreq);
      if (oldFreq == minFreq)
        minFreq++;
    }

    freqMap[key] = newFreq;
    freqKeyMap[newFreq].push_back(key);
    iteratorMap[key] = prev(freqKeyMap[newFreq].end());
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
