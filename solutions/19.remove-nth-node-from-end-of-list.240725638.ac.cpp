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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *ptr1 = dummy;
    ListNode *ptr2 = dummy;

    for (int i = 0; i <= n; i++)
      ptr2 = ptr2->next;

    while (ptr2) {
      ptr2 = ptr2->next;
      ptr1 = ptr1->next;
    }

    ptr1->next = ptr1->next->next;

    return dummy->next;
  }
};
