class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    vector<int> count1(256);
    vector<int> count2(256);
    for (char c : s1)
      count1[c]++;

    for (int i = 0; i < s2.size(); i++) {
      if (i >= s1.size()) {
        count2[s2[i - s1.size()]]--;
      }
      count2[s2[i]]++;
      if (count1 == count2)
        return true;
    }

    return false;
  }
};
