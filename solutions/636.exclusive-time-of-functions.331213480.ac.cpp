
class Solution {
public:
  vector<int> exclusiveTime(int n, vector<string> &logs) {
    vector<int> ans(n);
    stack<int> eventStack;

    int prev = 0;

    for (string &log : logs) {

      int r = log.rfind(':');
      int l = log.find(':');

      string event_s = log.substr(l + 1, r - 1 - l);

      int time = stoi(log.substr(r + 1));
      int id = stoi(log.substr(0, l));

      char event = event_s == "start" ? 's' : 'e';

      if (event == 's') {
        if (eventStack.size()) {
          ans[eventStack.top()] += time - prev;
        }
        eventStack.push(id);
        prev = time;
      } else {
        eventStack.pop();
        ans[id] += time - prev + 1;
        prev = time + 1;
      }
    }

    return ans;
  }
};
