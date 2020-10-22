/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
  void findSecretWord(vector<string> &wordlist, Master &master) {
    vector<string> set(wordlist.begin(), wordlist.end());

    while (true) {
      int i = rand() % set.size();
      string w = set[i];
      int score = master.guess(w);
      if (score == w.size())
        return;

      vector<string> new_set;
      for (string word : set) {
        if (matchScore(word, w) == score && word != w)
          new_set.push_back(word);
      }
      swap(new_set, set);
    }
  }

  int matchScore(string w1, string &w2) {
    int n = w1.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (w1[i] == w2[i])
        ans++;
    }
    return ans;
  }
};
