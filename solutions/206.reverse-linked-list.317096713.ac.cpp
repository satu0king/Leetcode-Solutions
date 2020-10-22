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
  ListNode *reverseListR(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *reversedList = reverseListR(head->next);
    head->next->next = head;
    head->next = NULL;
    return reversedList;
  }
  ListNode *reverseList(ListNode *head) {

    ListNode *prev = NULL;
    ListNode *current = head;

    while (current) {
      ListNode *temp = current->next;
      current->next = prev;
      prev = current;
      current = temp;
    }

    return prev;
  }
};
