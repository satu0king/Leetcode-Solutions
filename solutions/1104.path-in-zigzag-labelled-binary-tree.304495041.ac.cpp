

class Solution {

  int flip(int n, int level) {
    int levelElements = 1 << (level - 1);
    int prevElements = levelElements - 1;

    return prevElements + (levelElements - (n - prevElements) + 1);
  }

public:
  vector<int> pathInZigZagTree(int label) {
    int level = 0;
    for (; label >= (1 << level); level++)
      ;
    vector<int> ans;

    while (label) {
      ans.push_back(label);

      label /= 2;
      level--;
      if (level)
        label = flip(label, level);
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
