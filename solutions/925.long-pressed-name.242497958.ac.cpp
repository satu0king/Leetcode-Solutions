class Solution {
public:
  bool isLongPressedName(string name, string typed) {
    int n1 = name.size();
    int n2 = typed.size();
    if (!n1 || !n2)
      return false;
    if (name[0] != typed[0])
      return false;

    int i = 1;
    int j = 1;
    while (i < n1 && j < n2)
      if (name[i] == typed[j])
        i++, j++;
      else if (typed[j] == typed[j - 1])
        j++;
      else
        return false;

    while (j < n2 && typed[j] == typed[j - 1])
      j++;

    return j == n2 && i == n1;
  }
};
