class CombinationIterator {
  string s;
  int l;
  vector<int> indices;
  bool _hasNext = true;
  void _setNext() {
    for (int i = l - 1; i >= 0; i--) {
      if (indices[i] != s.size() - (l - i)) {
        indices[i]++;
        for (int j = i + 1; j < l; j++) {
          indices[j] = indices[j - 1] + 1;
        }
        return;
      }
    }
    _hasNext = false;
  }

public:
  CombinationIterator(string characters, int combinationLength)
      : s(characters), l(combinationLength), indices(l) {
    for (int i = 0; i < l; i++)
      indices[i] = i;
  }

  string next() {
    string result = "";
    for (int idx : indices)
      result += s[idx];

    _setNext();
    return result;
  }

  bool hasNext() { return _hasNext; }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */
