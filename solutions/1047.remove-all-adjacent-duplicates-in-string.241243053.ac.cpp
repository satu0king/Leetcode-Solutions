class Solution {
public:
  string removeDuplicates(string S) {
    vector<char> stack;
    for (char c : S) {
      if (stack.size()) {
        if (stack.back() == c)
          stack.pop_back();
        else
          stack.push_back(c);
      } else
        stack.push_back(c);
    }

    string ans = "";
    for (char c : stack)
      ans += c;
    return ans;
  }
};
