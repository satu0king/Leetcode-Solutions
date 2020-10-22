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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummyNode = new ListNode(0);
    ListNode *temp = dummyNode;
    int carry = 0;

    while (l1 || l2 || carry) {

      int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
      carry = sum / 10;

      temp->next = new ListNode(sum % 10);
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
      temp = temp->next;
    }
    return dummyNode->next;
  }
};
