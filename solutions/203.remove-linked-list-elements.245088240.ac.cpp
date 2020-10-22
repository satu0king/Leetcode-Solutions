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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *temp = dummy;
    while (temp) {
      while (temp->next && temp->next->val == val)
        temp->next = temp->next->next;
      temp = temp->next;
    }

    return dummy->next;
  }
};
