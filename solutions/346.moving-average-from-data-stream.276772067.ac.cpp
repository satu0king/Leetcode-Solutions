class MovingAverage {

  queue<int> slidingWindow;
  int size;
  int sum;

public:
  /** Initialize your data structure here. */
  MovingAverage(int size) : size(size), sum(0) {}

  double next(int val) {
    slidingWindow.push(val);
    sum += val;
    if (slidingWindow.size() > size) {
      sum -= slidingWindow.front();
      slidingWindow.pop();
    }
    return (double)sum / slidingWindow.size();
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
