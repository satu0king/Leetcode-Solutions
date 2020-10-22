/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
  vector<NestedInteger> &list;
  int i = 0;
  NestedIterator *current = NULL;

public:
  NestedIterator(vector<NestedInteger> &nestedList) : list(nestedList) {
    proceed();
  }

  int next() {

    int result = -1;
    if (list[i].isInteger()) {
      result = list[i].getInteger();
      i++;
      proceed();
    } else {
      result = current->next();
      if (!current->hasNext()) {
        i++;
        delete current;
        current = NULL;
        proceed();
      }
    }

    return result;
  }

  void proceed() {
    while (hasNext() && !list[i].isInteger() && !current) {
      current = new NestedIterator(list[i].getList());
      if (!current->hasNext()) {
        i++;
        delete current;
        current = NULL;
      }
    }
  }

  bool hasNext() { return i != list.size(); }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
