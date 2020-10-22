class SnapshotArray {

  vector<map<int, int>> snapArray;
  int snapId;

public:
  SnapshotArray(int length) : snapId(0), snapArray(length) {}

  void set(int index, int val) { snapArray[index][snapId] = val; }

  int snap() { return snapId++; }

  int get(int index, int snap_id) {
    auto it = snapArray[index].upper_bound(snap_id);
    if (it == snapArray[index].begin())
      return 0;
    else
      return prev(it)->second;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
