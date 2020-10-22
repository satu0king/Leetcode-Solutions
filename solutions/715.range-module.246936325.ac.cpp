
map<int, int>::iterator lower_bound2(map<int, int> &mp, int key) {
  if (mp.empty())
    return mp.end();

  auto it = mp.lower_bound(key);
  if (it->first == key)
    return it;

  if (it == mp.begin())
    return mp.end();

  it--;
  return it;
}

class RangeModule {

  map<int, int> mp;

public:
  RangeModule() {}

  void addRange(int left, int right) {
    removeRange(left, right);

    auto it = lower_bound2(mp, left);
    right--;

    if (it != mp.end() && it->second == left - 1)
      left = it->first;

    if (mp.count(right + 1)) {

      int t = right + 1;
      right = mp.find(t)->second;
      mp.erase(t);
    }

    mp[left] = right;
  }

  bool queryRange(int left, int right) {
    right--;

    auto it = lower_bound2(mp, left);

    return it != mp.end() && it->second >= right;
  }

  void removeRange(int left, int right) {
    right--;

    if (mp.empty())
      return;

    auto it = mp.lower_bound(left);

    if (it != mp.begin()) {
      it--;
      if (it->first < left) {
        if (it->second >= left) {
          if (it->second > right)
            mp[right + 1] = it->second;
          it->second = left - 1;
        }
      }
      it++;
    }

    while (it != mp.end() && it->first <= right) {
      auto temp = it;
      it++;
      if (temp->second > right)
        mp[right + 1] = temp->second;
      mp.erase(temp);
    }
  }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
