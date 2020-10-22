long long int p = 10e8 + 7;

long long int d = 31;

class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    unordered_map<long long int, int> map1;
    unordered_map<long long int, int> map2;

    int n = words.size();
    for (int i = 0; i < n; i++)
      map1[revHash(words[i])] = i;
    for (int i = 0; i < n; i++)
      map2[hash(words[i])] = i;

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
      string &word = words[i];
      int n1 = word.size();
      long long int h = 0;

      if (word == "") {
        for (int j = 0; j < n; j++) {
          if (j != i && isPalindrome(words[j], 0, words[j].size() - 1)) {
            ans.push_back({i, j});
            ans.push_back({j, i});
          }
        }
        continue;
      }

      for (int j = 0; j < n1; j++) {
        h = (h * d + word[j] - 'a' + 1) % p;
        if (map1.count(h) && map1[h] != i &&
            isPalindrome(word, j + 1, n1 - 1)) {
          if (j == n1 - 1 && map1[h] < i)
            continue;
          ans.push_back({i, map1[h]});
        }
      }
      h = 0;
      for (int j = n1 - 1; j >= 0; j--) {
        h = (h * d + word[j] - 'a' + 1) % p;
        if (map2.count(h) && map2[h] != i && isPalindrome(word, 0, j - 1)) {
          if (j == 0 && map2[h] < i)
            continue;
          ans.push_back({map2[h], i});
        }
      }
    }

    return ans;
  }

  bool isPalindrome(string &s, int l, int r) {

    while (l < r) {
      if (s[l] != s[r])
        return false;
      l++;
      r--;
    }

    return true;
  }

  long long int hash(string &s) {

    if (s == "")
      return -1;

    long long int h = 0;

    for (char c : s)
      h = (h * d + c - 'a' + 1) % p;

    return h;
  }

  long long int revHash(string s) {
    reverse(s.begin(), s.end());
    return hash(s);
  }
};
