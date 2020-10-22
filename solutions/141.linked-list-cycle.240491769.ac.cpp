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
  bool hasCycle(ListNode *head) {
    ListNode *first = head;
    ListNode *second;
    if (first)
      second = head->next;

    while (first && second) {
      second = second->next;
      if (second)
        second = second->next;
      first = first->next;
      if (first == second)
        return true;
    }

    return false;
  }
};
