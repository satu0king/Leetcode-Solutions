class Solution {
public:
  string reverseVowels(string s) {
    unordered_set<char> set = {'a', 'e', 'i', 'o', 'u',
                               'A', 'E', 'I', 'O', 'U'};

    int n = s.size();
    int l = 0;
    int r = n - 1;

    while (l <= r) {

      while (l <= r && !set.count(s[l]))
        l++;
      while (l <= r && !set.count(s[r]))
        r--;

      cout << l << " " << r << endl;

      if (l <= r)
        swap(s[l], s[r]);
      l++;
      r--;
    }
    return s;
  }
};
