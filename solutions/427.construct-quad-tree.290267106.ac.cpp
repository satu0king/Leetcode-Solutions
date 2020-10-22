/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/
class Solution {
public:
  Node *construct(vector<vector<int>> &grid, int ii = 0, int jj = 0,
                  int n = -1) {
    Node *temp = new Node(grid[ii][jj], true, NULL, NULL, NULL, NULL);

    // cout << ii << " " << jj <<" "<< n << endl;
    if (n == -1)
      n = grid.size();

    bool isLeaf = true;
    for (int i = ii; i < ii + n && isLeaf; i++) {
      for (int j = jj; j < jj + n; j++) {
        if (grid[i][j] != grid[ii][jj]) {
          isLeaf = false;
          break;
        }
      }
    }

    if (isLeaf) {
      // temp->val = (grid[ii][ii]  == 1);
      return temp;
    }
    temp->isLeaf = false;
    temp->val = false;
    temp->topLeft = construct(grid, ii, jj, n / 2);
    temp->topRight = construct(grid, ii, jj + n / 2, n / 2);
    temp->bottomLeft = construct(grid, ii + n / 2, jj, n / 2);
    temp->bottomRight = construct(grid, ii + n / 2, jj + n / 2, n / 2);

    return temp;
  }
};
