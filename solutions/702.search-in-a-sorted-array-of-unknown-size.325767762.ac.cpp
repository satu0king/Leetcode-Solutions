/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
  int search(const ArrayReader &reader, int target) {
    int size = 1;
    int out = 2147483647;
    while (reader.get(size) != out)
      size *= 2;

    int lsize = 1;
    int rsize = size;
    size = 0;
    while (lsize <= rsize) {
      int m = (lsize + rsize) / 2;
      if (reader.get(m - 1) == out)
        rsize = m - 1;
      else {
        size = m;
        lsize = m + 1;
      }
    }

    int l = 0;
    int r = size - 1;

    while (l <= r) {
      int m = (l + r) / 2;
      if (reader.get(m) == target)
        return m;
      else if (reader.get(m) > target)
        r = m - 1;
      else
        l = m + 1;
    }

    return -1;
  }
};
