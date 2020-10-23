/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *plusOne(ListNode *head) {
    if (f(head)) {
      ListNode *newHead = new ListNode(1);
      newHead->next = head;
      return newHead;
    }

    return head;
  }

  int f(ListNode *head) {
    if (head->next == NULL || f(head->next)) {
      if (head->val == 9) {
        head->val = 0;
        return 1;
      }
      head->val++;
    }
    return 0;
  }
};
