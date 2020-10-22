class Solution {
  int f(int x) {
    if (x == 1)
      return 0;
    if (x % 2)
      return f(x * 3 + 1) + 1;
    return f(x / 2) + 1;
  }

public:
  int getKth(int lo, int hi, int k) {

    vector<int> score(1001);
    for (int i = lo; i <= hi; i++)
      score[i] = f(i);
    auto cmp = [&](int x, int y) {
      return score[x] == score[y] ? x < y : score[x] < score[y];
    };
    vector<int> temp(hi - lo + 1);
    iota(temp.begin(), temp.end(), lo);
    nth_element(temp.begin(), temp.begin() + k - 1, temp.end(), cmp);
    return temp[k - 1];
  }
};
