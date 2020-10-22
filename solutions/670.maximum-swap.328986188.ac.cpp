class Solution {
public:
  int maximumSwap(int num) {
    string n = to_string(num);
    for (int i = 0; i < n.size(); i++) {

      int idx = i;

      for (int j = i + 1; j < n.size(); j++)
        if (n[j] >= n[idx])
          idx = j;
      if (n[idx] != n[i]) {
        swap(n[idx], n[i]);
        return stoi(n);
      }
    }

    return num;
  }
};
