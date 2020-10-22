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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummyNode = new ListNode(0);

    ListNode *temp = dummyNode;
    ListNode *next;

    while (l1 && l2) {
      if (l2->val < l1->val) {
        next = l2;
        l2 = l2->next;
      } else {
        next = l1;
        l1 = l1->next;
      }
      temp->next = next;
      temp = next;
    }

    if (l1)
      temp->next = l1;

    if (l2)
      temp->next = l2;

    return dummyNode->next;
  }
};
