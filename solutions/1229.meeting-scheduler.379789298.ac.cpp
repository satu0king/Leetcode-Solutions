class Solution {
public:
  vector<int> minAvailableDuration(vector<vector<int>> &slots1,
                                   vector<vector<int>> &slots2, int duration) {

    int i = 0;
    int j = 0;
    int n1 = slots1.size();
    int n2 = slots2.size();

    sort(slots1.begin(), slots1.end());
    sort(slots2.begin(), slots2.end());

    while (i < n1 && j < n2) {
      int l = max(slots1[i][0], slots2[j][0]);
      int r = min(slots1[i][1], slots2[j][1]);
      if (r - l >= duration) {
        return {l, l + duration};
      }
      if (slots1[i][1] < slots2[j][1])
        i++;
      else
        j++;
    }

    return {};
  }
};
