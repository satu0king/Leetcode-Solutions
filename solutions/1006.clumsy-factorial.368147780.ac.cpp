class Solution {
public:
  int clumsy(int N) {
    int ans = 0;
    vector<int> temp;
    int i = 1;
    while (i <= N) {
      int t = (N - i + 1);
      if (i + 1 <= N)
        t *= (N - i);
      if (i + 2 <= N)
        t /= (N - i - 1);
      temp.push_back(t);
      if (i + 3 <= N)
        temp.push_back(N - i - 2);
      i += 4;
    }
    ans = temp[0];

    for (int i = 1; i < temp.size(); i++) {
      if (i % 2)
        ans += temp[i];
      else
        ans -= temp[i];
    }
    return ans;
  }
};
