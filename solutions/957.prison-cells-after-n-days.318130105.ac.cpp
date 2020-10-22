class Solution {
public:
  vector<int> prisonAfterNDays(vector<int> &cells, int N) {
    vector<int> seen(256, -1);

    int current = 0;
    for (int i = 0; i < 8; i++)
      current |= cells[i] << i;

    int done;
    seen[current] = 0;
    for (done = 1; done <= N; done++) {
      current = next(current);
      if (~seen[current]) {
        int cycle = done - seen[current];
        done += cycle * ((N - done) / cycle);
      }
      seen[current] = done;
    }

    int t = current;

    vector<int> result;
    for (int i = 0; i < 8; i++)
      result.push_back(t & (1 << i) ? 1 : 0);

    return result;
  }

  int next(int state) {
    int nextState = 0;
    for (int i = 1; i < 7; i++) {

      bool s1 = state & (1 << (i - 1));
      bool s2 = state & (1 << (i + 1));

      if (!(s1 ^ s2))
        nextState ^= 1 << i;
    }
    return nextState;
  }
};
