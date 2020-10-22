/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  int getDecimalValue(ListNode *head) {
    int cnt = 1;
    int ans = 0;
    while (head != NULL) {
      ans = ans * 2;
      if (head->val != 0) {
        ans += 2;
      }
      head = head->next;
      cnt++;
    }
    ans = ans / 2;
    return ans;
  }
};
