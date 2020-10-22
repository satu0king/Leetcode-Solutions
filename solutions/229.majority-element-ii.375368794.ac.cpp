class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int candidate1 = 0;
    int candidate2 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int a : nums) {
      if (candidate1 == a)
        count1++;
      else if (candidate2 == a)
        count2++;
      else if (count1 == 0) {
        candidate1 = a;
        count1 = 1;
      } else if (count2 == 0) {
        candidate2 = a;
        count2 = 1;
      } else {
        count1--;
        count2--;
      }
    }
    count1 = 0;
    count2 = 0;
    for (int a : nums) {
      if (a == candidate1)
        count1++;
      else if (a == candidate2)
        count2++;
    }
    vector<int> ans;
    if (count1 > nums.size() / 3)
      ans.push_back(candidate1);
    if (count2 > nums.size() / 3)
      ans.push_back(candidate2);
    return ans;
  }
};
