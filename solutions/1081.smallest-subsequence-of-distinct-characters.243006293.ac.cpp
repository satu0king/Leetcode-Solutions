class Solution {
public:
  string smallestSubsequence(string s) {
    unordered_map<char, int> map;
    unordered_set<char> set;
    for (char c : s)
      map[c]++;

    vector<char> stack;
    for (char c : s) {
      map[c]--;

      if (set.find(c) == set.end()) {
        while (!stack.empty() && stack.back() > c && map[stack.back()]) {
          set.erase(stack.back());
          stack.pop_back();
        }
        stack.push_back(c);
        set.insert(c);
      }
    }

    string ans;
    for (char c : stack)
      ans += c;

    return ans;
  }
};
