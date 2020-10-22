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
    while (temp->next) {

      int v = temp->next->val;
      ListNode *temp2 = temp->next;
      while (temp2 && temp2->val == v)
        temp2 = temp2->next;
      if (temp2 == temp->next->next)
        temp = temp->next;
      else
        temp->next = temp2;
    }

    return dummy->next;
  }
};
