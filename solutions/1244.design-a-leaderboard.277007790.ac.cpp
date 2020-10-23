class Leaderboard {
  map<int, int> scores;
  unordered_map<int, int> scoreMap;

public:
  Leaderboard() {}

  void addScore(int playerId, int score) {
    // reset(playerId);

    if (scoreMap.count(playerId)) {
      score += scoreMap[playerId];
      scores[scoreMap[playerId]]--;
    }

    scores[score]++;
    scoreMap[playerId] = score;
  }

  int top(int K) {
    int ans = 0;

    cout << K << endl;

    for (auto it = scores.rbegin(); it != scores.rend() && K; it++) {
      ans += it->first * min(it->second, K);
      K -= min(it->second, K);
    }

    return ans;
  }

  void reset(int playerId) {
    if (scoreMap.count(playerId)) {
      int oldScore = scoreMap[playerId];
      scores[oldScore]--;
      scoreMap.erase(playerId);
    }
  }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
