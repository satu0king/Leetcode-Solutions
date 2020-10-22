class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K) {
    multiset<pair<double, int>> wages;

    int n = quality.size();
    for (int i = 0; i < n; i++)
      wages.emplace((0.0 + wage[i]) / quality[i], quality[i]);

    multiset<int> wagePQ;

    double ans = INT_MAX;
    int qualitySum = 0;

    for (auto p : wages) {
      double r = p.first;
      int quality = p.second;
      qualitySum += quality;
      wagePQ.insert(quality);

      if (wagePQ.size() > K) {
        qualitySum -= *wagePQ.rbegin();
        wagePQ.erase(wagePQ.find(*wagePQ.rbegin()));
      }

      if (wagePQ.size() == K) {
        ans = min(ans, r * qualitySum);
      }
      // cout<<qualitySum<<" "<<r<<" "<<wagePQ.size()<<endl;
    }

    return ans;
  }
};
