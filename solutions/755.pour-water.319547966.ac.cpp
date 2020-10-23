class Solution {
public:
  vector<int> pourWater(vector<int> &heights, int V, int K) {
    set<pair<int, int>> left_pq;
    set<pair<int, int>> right_pq;
    int n = heights.size();

    addLeft(left_pq, heights, K);
    addRight(right_pq, heights, K);

    while (V--) {
      if (left_pq.size() && left_pq.begin()->first < heights[K]) {
        auto p = *left_pq.begin();
        left_pq.erase(p);
        int i = abs(p.second);
        // cout << p.first << endl;
        heights[i]++;
        p.first++;
        left_pq.insert(p);
        addLeft(left_pq, heights, i);
      } else if (right_pq.size() && right_pq.begin()->first < heights[K]) {
        auto p = *right_pq.begin();
        right_pq.erase(p);
        int i = abs(p.second);
        // cout << p.first << endl;
        heights[i]++;
        p.first++;
        right_pq.insert(p);
        addRight(right_pq, heights, i);
      } else {
        heights[K]++;
        addLeft(left_pq, heights, K);
        addRight(right_pq, heights, K);
      }
      // for(int i = 0; i < n; i++)
      //     cout << heights[i] <<" ";
      // cout << endl;
    }

    return heights;
  }

  void addLeft(set<pair<int, int>> &pq, vector<int> &heights, int i) {

    int mn = heights[i];

    for (int j = i - 1; j >= 0; j--) {
      if (heights[j] > mn)
        break;
      auto p = make_pair(heights[j], -j);
      if (pq.count(p))
        break;
      mn = min(heights[j], mn);
      pq.insert(p);
    }
  }

  void addRight(set<pair<int, int>> &pq, vector<int> &heights, int i) {
    int n = heights.size();
    int mn = heights[i];

    for (int j = i + 1; j < n; j++) {
      if (heights[j] > mn)
        break;
      auto p = make_pair(heights[j], j);
      if (pq.count(p))
        break;
      mn = min(heights[j], mn);
      pq.insert(p);
    }
  }
};
