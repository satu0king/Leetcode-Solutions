class Solution {
public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                               vector<int> &rightChild) {
    if (n == 1)
      return true;
    int edgeCount = 0;
    vector<bool> hasParent(n);
    for (int i = 0; i < n; i++) {
      if (~leftChild[i]) {
        if (hasParent[leftChild[i]])
          return false;
        hasParent[leftChild[i]] = true;
        edgeCount++;
      }
      if (~rightChild[i]) {
        if (hasParent[rightChild[i]])
          return false;
        hasParent[rightChild[i]] = true;
        edgeCount++;
      }
    }
    if (edgeCount != n - 1)
      return false;

    for (int i = 0; i < n; i++) {
      if (!hasParent[i])
        return ~leftChild[i] || ~rightChild[i];
    }
    return false;
  }
};
