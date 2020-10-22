class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {

    vector<int> stack;

    for (int i = 0; i < asteroids.size(); i++) {
      int n1 = asteroids[i];
      if (stack.empty())
        stack.push_back(n1);
      else {
        if (n1 < 0) {
          if (stack.back() > 0) {
            if (stack.size() && stack.back() == -n1) {
              stack.pop_back();
            } else if (stack.size() && stack.back() > -n1) {
              continue;
            } else if (stack.size() && stack.back() < -n1) {
              stack.pop_back();
              i--;
            }
          } else
            stack.push_back(n1);
        } else {
          stack.push_back(n1);
        }
      }
    }

    return stack;
  }
};
