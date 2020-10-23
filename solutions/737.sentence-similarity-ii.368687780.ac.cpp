struct DSU {
  vector<int> size;
  vector<int> parent;
  DSU(int n) : size(n), parent(n) {
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int getSet(int i) {
    if (parent[i] == i)
      return i;
    return parent[i] = getSet(parent[i]);
  }

  void join(int i, int j) {
    i = getSet(i);
    j = getSet(j);
    if (i == j)
      return;
    if (size[i] < size[j])
      swap(i, j);
    parent[j] = i;
    size[i] += size[j];
  }
};

class Solution {
public:
  bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2,
                              vector<vector<string>> &pairs) {
    if (words1.size() != words2.size())
      return false;
    unordered_map<string, int> mp;
    int c = 0;
    for (auto &w : words1)
      if (!mp.count(w))
        mp[w] = c++;
    for (auto &w : words2)
      if (!mp.count(w))
        mp[w] = c++;

    for (auto &p : pairs) {
      if (!mp.count(p[0]))
        mp[p[0]] = c++;
      if (!mp.count(p[1]))
        mp[p[1]] = c++;
    }
    DSU dsu(c);
    for (auto &p : pairs)
      dsu.join(mp[p[0]], mp[p[1]]);

    for (int i = 0; i < words1.size(); i++)
      if (dsu.getSet(mp[words1[i]]) != dsu.getSet(mp[words2[i]]))
        return false;
    return true;
  }
};
