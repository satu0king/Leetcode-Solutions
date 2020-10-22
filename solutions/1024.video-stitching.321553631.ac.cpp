class Solution {
public:
  int videoStitching(vector<vector<int>> &clips, int T) {

    sort(clips.begin(), clips.end());

    int n = clips.size();
    int ans = 0;
    for (int i = 0, start = 0, end = 0; start < T; ans++, start = end) {
      while (i < n && clips[i][0] <= start)
        end = max(end, clips[i++][1]);

      if (end == start)
        return -1;
    }

    return ans;
  }
};
