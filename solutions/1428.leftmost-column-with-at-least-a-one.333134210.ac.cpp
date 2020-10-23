/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    int n = binaryMatrix.dimensions()[0];
    int m = binaryMatrix.dimensions()[1];

    int ans = m;
    for (int i = 0; i < n; i++)
      while (ans && binaryMatrix.get(i, ans - 1))
        ans--;

    return ans == m ? -1 : ans;
  }
};
