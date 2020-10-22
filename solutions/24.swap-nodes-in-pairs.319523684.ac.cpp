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
  ListNode *swapPairs(ListNode *head) {
    if (!head)
      return NULL;
    if (!head->next)
      return head;

    auto dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prevNode = dummy;

    while (head && head->next) {
      auto first = head;
      auto second = head->next;

      first->next = second->next;
      prevNode->next = second;
      second->next = first;
      prevNode = first;
      head = first->next;
    }

    return dummy->next;
  }
};
