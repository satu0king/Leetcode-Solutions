class Solution {
public:
  vector<double> sampleStats(vector<int> &count) {
    int c = accumulate(count.begin(), count.end(), 0);

    vector<double> ans(5);

    int mi = -1;
    for (int i = 255; i >= 0; i--)
      if (count[i])
        mi = i;

    int mx = -1;
    for (int i = 0; i < 256; i++)
      if (count[i])
        mx = i;

    int mode = -1;

    for (int i = 0; i < 256; i++)
      if (count[i] && (mode == -1 || count[i] > count[mode]))
        mode = i;

    ans[0] = mi;
    ans[1] = mx;

    for (int i = 0; i < 256; i++)
      ans[2] += count[i] * i;

    ans[2] /= c;

    ans[4] = mode;

    int t = 0;

    int target1 = (c - 1) / 2 + 1;
    int target2 = c / 2 + 1;

    cout << c << endl;
    cout << target1 << endl;
    cout << target2 << endl;

    for (int i = 0; i < 256; i++) {
      if (count[i] && count[i] + t >= target1 && t < target1)
        ans[3] += i;

      if (count[i] && count[i] + t >= target2 && t < target2)
        ans[3] += i;

      t += count[i];
    }

    ans[3] /= 2;

    return ans;
  }
};
