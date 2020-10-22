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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dummy = new ListNode(INT_MIN);
    dummy->next = head;

    ListNode *temp = dummy;
    while (temp) {
      while (temp->next && temp->next->val == temp->val)
        temp->next = temp->next->next;
      temp = temp->next;
    }

    return dummy->next;
  }
};
