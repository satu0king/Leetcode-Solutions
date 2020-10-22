struct BalloonEvent {
  int balloonId;
  bool isStart;
  int xCoordinate;
  bool operator<(const BalloonEvent &other) const {
    if (xCoordinate == other.xCoordinate)
      return isStart; // Order Start events before end Event
    return xCoordinate < other.xCoordinate;
  }
};

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    vector<BalloonEvent> balloonEvents;
    int balloonCount = points.size();
    for (int i = 0; i < balloonCount; i++) {
      int startX = points[i][0];
      int endX = points[i][1];
      balloonEvents.push_back({i, true, startX});
      balloonEvents.push_back({i, false, endX});
    }
    sort(balloonEvents.begin(), balloonEvents.end());
    stack<int> balloonStack;
    vector<bool> balloonBursted(balloonCount);
    int ans = 0;
    for (auto &event : balloonEvents) {
      auto [id, isStart, xCoordinate] = event;
      if (isStart)
        balloonStack.push(id);
      else {
        if (!balloonBursted[id]) {
          ans++;
          while (balloonStack.size()) {
            int id = balloonStack.top();
            balloonStack.pop();
            balloonBursted[id] = true;
          }
        }
      }
    }
    return ans;
  }
};
