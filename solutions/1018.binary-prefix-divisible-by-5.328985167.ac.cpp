class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int> &A) {
    vector<bool> ans;
    int running = 0;
    for (int a : A) {
      running *= 2;
      if (a)
        running++;
      running %= 5;
      ans.push_back(!running);
    }
    return ans;
  }
};
