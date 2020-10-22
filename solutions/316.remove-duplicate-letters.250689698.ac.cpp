class Solution {
public:
  string removeDuplicateLetters(string s) {
    unordered_map<char, int> map;
    unordered_set<char> set;
    for (char c : s)
      map[c]++;

    vector<char> stack;
    unordered_set<char> done;

    for (char c : s) {

      while (!done.count(c) && stack.size() && stack.back() >= c &&
             map[stack.back()]) {
        done.erase(stack.back());
        stack.pop_back();
      }
      if (!done.count(c)) {
        stack.push_back(c);
        done.insert(c);
      }

      map[c]--;
    }

    string ans = "";
    for (char c : stack)
      ans += c;
    return ans;
  }
};
