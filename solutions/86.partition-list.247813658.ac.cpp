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
  ListNode *partition(ListNode *head, int x) {

    ListNode *dummyHead1 = new ListNode(0);
    ListNode *dummyHead2 = new ListNode(0);
    ListNode *dummyTail1 = dummyHead1;
    ListNode *dummyTail2 = dummyHead2;

    while (head) {

      if (head->val < x) {
        dummyTail1->next = head;
        dummyTail1 = dummyTail1->next;
      } else {
        dummyTail2->next = head;
        dummyTail2 = dummyTail2->next;
      }

      head = head->next;
    }

    dummyTail1->next = dummyHead2->next;
    dummyTail2->next = NULL;
    return dummyHead1->next;
  }
};
