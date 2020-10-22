class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> mp;

    for (auto num : nums) {
      if (mp.find(num) == mp.end())
        mp[num] = 1;
      else
        mp[num] += 1;
    }

    priority_queue<pair<int, int>> pq;

    for (auto &n : mp) {
      pq.push(make_pair(-n.second, n.first));
      if (pq.size() > k)
        pq.pop();
    }
    vector<int> ans;

    while (!pq.empty()) {
      ans.push_back(pq.top().second);
      pq.pop();
    }

    return ans;
  }
};
