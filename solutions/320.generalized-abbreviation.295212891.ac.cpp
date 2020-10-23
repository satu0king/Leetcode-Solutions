class Solution {
public:
  vector<string> generateAbbreviations(string word) {
    vector<string> result;
    int n = word.size();
    string path = "";
    f(result, word, 0, path);
    // sort(result.begin(), result.end());
    // result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
  }

  void f(vector<string> &result, string &word, int i, string &path,
         bool flag = false) {

    int n = word.size();

    if (i == n) {
      result.push_back(path);
      return;
    }

    for (int c = 1; i + c <= n; c++)
      if (!flag) {
        path += to_string(c);
        int z = to_string(c).size();
        f(result, word, i + c, path, true);
        path.erase(path.end() - z, path.end());
      }

    path += word[i];
    f(result, word, i + 1, path);
    path.pop_back();
  }
};
