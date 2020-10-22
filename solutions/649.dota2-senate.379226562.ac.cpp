class Solution {
public:
  string predictPartyVictory(string senate) {
    vector<int> count(2);
    vector<int> ban(2);

    deque<int> q;
    for (char c : senate) {
      int z = (c == 'R');
      count[z]++;
      q.push_back(z);
    }

    while (q.size()) {
      int z = q.front();
      q.pop_front();
      if (ban[z]) {
        ban[z]--;
        continue;
      }
      if (count[z ^ 1] == 0)
        return z ? "Radiant" : "Dire";

      ban[z ^ 1]++;
      count[z ^ 1]--;
      q.push_back(z);
    }

    return "";
  }
};
