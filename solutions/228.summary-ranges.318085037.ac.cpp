class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<pair<int, int>> ranges;

    for (int n : nums) {
      if (ranges.empty() || ranges.back().second + 1 != n)
        ranges.emplace_back(n, n);
      else
        ranges.back().second++;
    }

    vector<string> result;

    for (auto &p : ranges)
      if (p.first == p.second)
        result.push_back(to_string(p.first));
      else
        result.push_back(to_string(p.first) + "->" + to_string(p.second));

    return result;
  }
};
