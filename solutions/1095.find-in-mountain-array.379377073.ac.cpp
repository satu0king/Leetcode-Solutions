/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int l = 0;
    int n = mountainArr.length();
    int r = n - 2;

    int mountain = -1;

    while (l <= r) {
      int mid = (l + r) / 2;
      int mid_value = mountainArr.get(mid);
      int next_value = mountainArr.get(mid + 1);
      if (mid_value < next_value)
        l = mid + 1;
      else {
        mountain = mid;
        r = mid - 1;
      }
    }

    {
      int l = 0;
      int r = mountain;

      while (l <= r) {
        int mid = (l + r) / 2;
        int mid_value = mountainArr.get(mid);
        if (mid_value == target)
          return mid;
        else if (mid_value < target)
          l = mid + 1;
        else
          r = mid - 1;
      }
    }

    {
      int l = mountain;
      int r = n - 1;

      while (l <= r) {
        int mid = (l + r) / 2;
        int mid_value = mountainArr.get(mid);
        if (mid_value == target)
          return mid;
        else if (mid_value > target)
          l = mid + 1;
        else
          r = mid - 1;
      }
    }

    return -1;
  }
};
