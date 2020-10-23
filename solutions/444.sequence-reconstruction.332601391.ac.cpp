class Solution {
public:
  bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &_seqs) {

    int n = org.size();
    vector<vector<int>> seqs;
    for (auto &s : _seqs)
      if (s.size()) {
        for (int i = 0; i + 1 < s.size(); i++)
          if (s[i] == s[i + 1])
            return false;

        for (int i = 0; i < s.size(); i++)
          if (s[i] < 1 || s[i] > n)
            return false;
        seqs.push_back(s);
      }

    if (n == 1)
      return seqs.size();

    vector<int> outDegree(n + 1);
    vector<unordered_set<int>> parent(n + 1);

    int c = 0;

    for (auto &seq : seqs) {
      for (int i = 0; i + 1 < seq.size(); i++) {
        if (!parent[seq[i + 1]].count(seq[i])) {
          parent[seq[i + 1]].insert(seq[i]);
          if (outDegree[seq[i]]++ == 0)
            c++;
        }
      }
    }

    if (c != n - 1)
      return false;

    for (int i = n - 1; i >= 0; i--) {
      if (outDegree[org[i]])
        return false;
      for (int p : parent[org[i]])
        if (--outDegree[p] == 0 && p != org[i - 1])
          return false;
    }

    return true;
  }
};
