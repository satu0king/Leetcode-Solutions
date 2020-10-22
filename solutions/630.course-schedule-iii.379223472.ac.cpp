bool cmp(vector<int> &v1, vector<int> &v2) { return v1[1] < v2[1]; }

class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    sort(courses.begin(), courses.end(), cmp);
    priority_queue<int> pq;
    int currentTime = 0;
    for (auto &course : courses) {
      int time = course[0];
      int deadline = course[1];
      if (currentTime + time <= deadline) {
        pq.push(time);
        currentTime += time;
      } else if (pq.size() && pq.top() >= time) {
        currentTime -= pq.top();
        pq.pop();
        pq.push(time);
        currentTime += time;
      }
    }
    return pq.size();
  }
};
