class Solution {
  unordered_map<char, char> mp = {
      {'6', '9'}, {'9', '6'}, {'8', '8'}, {'0', '0'}, {'1', '1'},
  };

public:
  vector<string> findStrobogrammatic(int n) {
    vector<string> ans;
    string temp(n, ' ');
    f(ans, temp, n);
    return ans;
  }
  void f(vector<string> &ans, string &temp, int n, int i = 0) {
    if (2 * i >= n) {
      ans.push_back(temp);
      return;
    }
    for (auto &p : mp) {
      if (i == n - i - 1) {
        if (p.first == '6')
          continue;
        if (p.first == '9')
          continue;
      }
      if (i == 0 && n > 1 && p.first == '0')
        continue;
      temp[i] = p.first;
      temp[n - i - 1] = p.second;
      f(ans, temp, n, i + 1);
    }
  }
};

// bool isStrobogrammatic(string num) {
//
//         int n = num.size();
//         for(int i = 0; i < n; i++) {
//             if(!mp.count(num[i]) || !mp.count(num[n - i - 1]))return false;
//             if(mp[num[i]] != num[n-i-1])return false;
//         }
//         return true;
//     }
