class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();
    vector<bool> visited(n);
    vector<int> stack;
    stack.push_back(0);
    while (!stack.empty()) {
      int room = stack.back();
      stack.pop_back();
      visited[room] = true;
      for (auto r : rooms[room])
        if (!visited[r])
          stack.push_back(r);
    }
    return find(visited.begin(), visited.end(), false) == visited.end();
  }
};
