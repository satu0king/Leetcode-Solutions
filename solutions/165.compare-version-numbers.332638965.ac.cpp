class Solution {
public:
  int compareVersion(string version1, string version2) {
    istringstream inp1(version1);
    istringstream inp2(version2);

    vector<int> v1;
    vector<int> v2;

    int v;
    char _;

    while (inp1 >> v) {
      v1.push_back(v);
      inp1 >> _;
    }
    while (inp2 >> v) {
      v2.push_back(v);
      inp2 >> _;
    }
    if (v1.size() < v2.size())
      v1.resize(v2.size());
    else if (v2.size() < v1.size())
      v2.resize(v1.size());

    if (v1 > v2)
      return 1;
    else if (v1 < v2)
      return -1;
    return 0;
  }
};
