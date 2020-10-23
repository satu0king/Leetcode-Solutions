class Logger {
  queue<pair<string, int>> queue;
  unordered_map<string, int> messageCount;

public:
  /** Initialize your data structure here. */
  Logger() {}

  /** Returns true if the message should be printed in the given timestamp,
     otherwise returns false. If this method returns false, the message will not
     be printed. The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    while (queue.size() && queue.front().second + 10 <= timestamp) {
      messageCount[queue.front().first]--;
      queue.pop();
    }
    if (messageCount[message] == 0) {
      messageCount[message]++;
      queue.emplace(message, timestamp);
      return true;
    }
    return false;
  }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
