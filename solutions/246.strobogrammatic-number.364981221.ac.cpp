class Solution {
public:
  bool isStrobogrammatic(string num) {
    unordered_map<char, char> mp = {
        {'6', '9'}, {'9', '6'}, {'8', '8'}, {'0', '0'}, {'1', '1'},
    };
    int n = num.size();
    for (int i = 0; i < n; i++) {
      if (!mp.count(num[i]) || !mp.count(num[n - i - 1]))
        return false;
      if (mp[num[i]] != num[n - i - 1])
        return false;
    }
    return true;
  }
};
