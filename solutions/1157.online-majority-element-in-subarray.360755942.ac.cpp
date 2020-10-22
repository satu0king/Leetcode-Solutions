class MajorityChecker {
  unordered_map<int, vector<int>> indexMap;
  vector<int> numbers;

public:
  MajorityChecker(vector<int> &arr) : numbers(arr) {
    for (int i = 0; i < arr.size(); i++) {
      indexMap[arr[i]].push_back(i);
    }
  }

  int query(int l, int r, int threshold) {
    int temp = -1;
    for (int i = 0; i < 10; i++) {
      int randIndex = rand() % (r - l + 1) + l;
      int randElement = numbers[randIndex];
      auto &indices = indexMap[randElement];
      auto upperIndexIterator = upper_bound(indices.begin(), indices.end(), r);
      auto lowerIndexIterator = lower_bound(indices.begin(), indices.end(), l);
      int count = upperIndexIterator - lowerIndexIterator;
      // cout << count << endl;
      if (count >= threshold) {
        temp = randElement;
        break;
      }
    }
    return temp;
  }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
