class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

    int capacity = 0;
    int deficit = 0;
    int j = 0;

    for (int i = 0; i < gas.size(); i++) {
      capacity += gas[i] - cost[i];
      if (capacity < 0) {
        deficit += capacity;
        capacity = 0;
        j = i + 1;
      }
    }

    if (capacity + deficit >= 0)
      return j;
    return -1;
  }
};
