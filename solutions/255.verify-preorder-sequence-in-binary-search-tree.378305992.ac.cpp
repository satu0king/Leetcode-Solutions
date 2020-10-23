class Solution {
public:
  bool verifyPreorder(vector<int> &preorder) {
    int i = 0;
    f(preorder, i);
    return i == preorder.size();
  }

  void f(vector<int> &preorder, int &i, int mx = INT_MAX, int mn = INT_MIN) {
    if (i == preorder.size())
      return;
    if (preorder[i] > mx)
      return;
    if (preorder[i] < mn)
      return;
    int root = preorder[i++];
    f(preorder, i, root, mn);
    f(preorder, i, mx, root);
  }
};
